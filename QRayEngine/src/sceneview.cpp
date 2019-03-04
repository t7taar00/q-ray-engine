#include "sceneview.h"

SceneView::SceneView(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0, 0, SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT);
    this->setFocusPolicy(Qt::StrongFocus);

    actorPosition = new ActorPosition;
    viewPlane = new ViewPlane;
    rayProjectile = new RayProjectile;

    textureReader = new TextureReader;
    inputHandler = new InputHandler(actorPosition, viewPlane);

    ticker.start(20, this);
}

SceneView::~SceneView()
{
    delete actorPosition;
    actorPosition = nullptr;

    delete viewPlane;
    viewPlane = nullptr;

    delete rayProjectile;
    rayProjectile = nullptr;

    delete textureReader;
    textureReader = nullptr;

    delete inputHandler;
    inputHandler = nullptr;
}

void SceneView::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if(event->key() == Qt::Key_A)
        inputHandler->inputEventTurnLeft();
    if(event->key() == Qt::Key_D)
        inputHandler->inputEventTurnRight();
    if(event->key() == Qt::Key_W)
        inputHandler->inputEventMoveForward();
    if(event->key() == Qt::Key_S)
        inputHandler->inputEventMoveBackwards();
    if(event->key() == Qt::Key_Q)
        inputHandler->inputEventStrafeLeft();
    if(event->key() == Qt::Key_E)
        inputHandler->inputEventStrafeRight();
}

void SceneView::timerEvent(QTimerEvent*)
{
    renderScene();
}

void SceneView::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawImage(0, 0, buffer);
    p.end();
}

void SceneView::renderScene()
{
    buffer = QImage(SCENE_VIEW_WIDTH, SCENE_VIEW_HEIGHT, QImage::Format_RGB32);

    for(int x = 0; x < SCENE_VIEW_WIDTH; x++)
    {
        // calculate ray position and direction
        double cameraX = 2 * x / static_cast<double>(SCENE_VIEW_WIDTH) - 1; // x-coordinate in camera space

        rayProjectile->calcRayDirX(actorPosition, viewPlane, cameraX);
        rayProjectile->calcRayDirY(actorPosition, viewPlane, cameraX);

        // which box of the map we're in
        int mapX = static_cast<int>(actorPosition->getPosX());
        int mapY = static_cast<int>(actorPosition->getPosY());

        actorPosition->setMapX(mapX);
        actorPosition->setMapY(mapY);

        // length of ray from one x or y-side to next x or y-side
        rayProjectile->calcDeltaDistX();
        rayProjectile->calcDeltaDistY();

        double perpWallDist;

        // what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; // was there a wall hit?
        int side = 0; // was a NS or a EW wall hit?

        // calculate step and initial sideDist
        stepX = rayProjectile->calcSideDistX(actorPosition);
        stepY = rayProjectile->calcSideDistY(actorPosition);

        // perform DDA
        while(hit == 0)
        {
            // jump to next map square, OR in x-direction, OR in y-direction
            side = rayProjectile->calcMapJump(actorPosition, stepX, stepY);

            mapX = actorPosition->getMapX();
            mapY = actorPosition->getMapY();

            // check if ray has hit a wall
            if(SceneMap::mapArray[mapX][mapY] > 0) hit = 1;
        }

        // calculate distance projected on camera direction
        if(side == 0) perpWallDist = (mapX - actorPosition->getPosX() + (1 - stepX) / 2) / rayProjectile->getRayDirX();
        else          perpWallDist = (mapY - actorPosition->getPosY() + (1 - stepY) / 2) / rayProjectile->getRayDirY();

        // calculate height of line to draw on screen
        int lineHeight = static_cast<int>(SCENE_VIEW_HEIGHT / perpWallDist);

        // calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + SCENE_VIEW_HEIGHT / 2;
        if(drawStart < 0) drawStart = 0;

        int drawEnd = lineHeight / 2 + SCENE_VIEW_HEIGHT / 2;
        if(drawEnd >= SCENE_VIEW_HEIGHT) drawEnd = SCENE_VIEW_HEIGHT - 1;

        int textureId = SceneMap::mapArray[mapX][mapY];

        // calculate value of wallX
        double wallX; // where exactly the wall was hit

        if(side == 0) wallX = actorPosition->getPosY() + perpWallDist * rayProjectile->getRayDirY();
        else          wallX = actorPosition->getPosX() + perpWallDist * rayProjectile->getRayDirX();

        wallX -= std::floor(wallX);

        // x coordinate on the texture
        int texX = static_cast<int>(wallX * TextureReader::textureWidth);

        if(side == 0 && rayProjectile->getRayDirX() > 0) texX = TextureReader::textureWidth - texX - 1;
        if(side == 1 && rayProjectile->getRayDirY() < 0) texX = TextureReader::textureWidth - texX - 1;

        for(int y = drawStart; y < drawEnd; y++)
        {
            int d = y * 256 - SCENE_VIEW_HEIGHT * 128 + lineHeight * 128;  // 256 and 128 factors to avoid floats
            // TODO: avoid the division to speed this up
            int texY = ((d * TextureReader::textureHeight) / lineHeight) / 256;

            QColor textureColor = textureReader->getTexturePixel(textureId, texX, texY);

            buffer.setPixelColor(x, y, textureColor);
        }

        // FLOOR CASTING
        double floorXWall, floorYWall; // x, y position of the floor texel at the bottom of the wall

        // 4 different wall directions possible
        if(side == 0 && rayProjectile->getRayDirX() > 0)
        {
            floorXWall = mapX;
            floorYWall = mapY + wallX;
        }
        else if(side == 0 && rayProjectile->getRayDirX() < 0)
        {
            floorXWall = mapX + 1.0;
            floorYWall = mapY + wallX;
        }
        else if(side == 1 && rayProjectile->getRayDirY() > 0)
        {
            floorXWall = mapX + wallX;
            floorYWall = mapY;
        }
        else
        {
            floorXWall = mapX + wallX;
            floorYWall = mapY + 1.0;
        }

        double distWall, distActor, currentDist;

        distWall = perpWallDist;
        distActor = 0.0;

        if(drawEnd < 0) drawEnd = SCENE_VIEW_HEIGHT; // becomes < 0 when the integer overflows

        // draw the floor from drawEnd to the bottom of the screen
        for(int y = drawEnd + 1; y < SCENE_VIEW_HEIGHT; y++)
        {
            currentDist = SCENE_VIEW_HEIGHT / (2.0 * y - SCENE_VIEW_HEIGHT);

            double weight = (currentDist - distActor) / (distWall - distActor);

            double currentFloorX = weight * floorXWall + (1.0 - weight) * actorPosition->getPosX();
            double currentFloorY = weight * floorYWall + (1.0 - weight) * actorPosition->getPosY();

            int floorTexX, floorTexY;
            floorTexX = static_cast<int>(currentFloorX * TextureReader::textureWidth) % TextureReader::textureWidth;
            floorTexY = static_cast<int>(currentFloorY * TextureReader::textureHeight) % TextureReader::textureHeight;

            // floor
            QColor texFloorColor = textureReader->getTexturePixel(TEXTURE_FLOOR, floorTexX, floorTexY);
            buffer.setPixelColor(x, y, texFloorColor);

            // ceiling
            QColor texCeilingColor = textureReader->getTexturePixel(TEXTURE_CEILING, floorTexX, floorTexY);
            buffer.setPixelColor(x, SCENE_VIEW_HEIGHT - y, texCeilingColor);
        }
    }
    update();
}

