#include "renderengine.h"

RenderEngine::RenderEngine(QWidget *parent, QImage *buffer)
{
    m_actorPosition = new ActorPosition;
    m_viewPlane = new ViewPlane;
    m_rayProjectile = new RayProjectile;

    m_textureReader = new TextureReader;
    m_inputHandler = new InputHandler(m_actorPosition, m_viewPlane);
}

RenderEngine::~RenderEngine()
{
    delete m_actorPosition;
    m_actorPosition = nullptr;

    delete m_viewPlane;
    m_viewPlane = nullptr;

    delete m_rayProjectile;
    m_rayProjectile = nullptr;

    delete m_textureReader;
    m_textureReader = nullptr;

    delete m_inputHandler;
    m_inputHandler = nullptr;
}

void RenderEngine::calculateFrame()
{
    for (qint32 x = 0; x < SCENE_VIEW_WIDTH; x = x + HORIZONTAL_SKIP) {
        // calculate ray position and direction
        // x-coordinate in camera space
        qreal cameraX = 2 * x / static_cast<qreal>(SCENE_VIEW_WIDTH) - 1;

        m_rayProjectile->calcRayDirX(m_actorPosition, m_viewPlane, cameraX);
        m_rayProjectile->calcRayDirY(m_actorPosition, m_viewPlane, cameraX);

        // which box of the map we're in
        quint8 mapX = static_cast<quint8>(m_actorPosition->getPosX());
        quint8 mapY = static_cast<quint8>(m_actorPosition->getPosY());

        m_actorPosition->setMapX(mapX);
        m_actorPosition->setMapY(mapY);

        // length of ray from one x or y-side to next x or y-side
        m_rayProjectile->calcDeltaDistX();
        m_rayProjectile->calcDeltaDistY();

        qreal perpWallDist;

        // what direction to step in x or y-direction (either +1 or -1)
        qint8 stepX;
        qint8 stepY;

        qint8 hit = 0; // was there a wall hit?
        qint8 side = 0; // was a NS or a EW wall hit?

        // calculate step and initial sideDist
        stepX = m_rayProjectile->calcSideDistX(m_actorPosition);
        stepY = m_rayProjectile->calcSideDistY(m_actorPosition);

        // perform DDA
        while (hit == 0) {
            // jump to next map square, OR in x-direction, OR in y-direction
            side = m_rayProjectile->calcMapJump(m_actorPosition, stepX, stepY);

            mapX = m_actorPosition->getMapX();
            mapY = m_actorPosition->getMapY();

            // check if ray has hit a wall
            if (SceneMap::mapArray[mapX][mapY] > 0)
                hit = 1;
        }

        // calculate distance projected on camera direction
        if (side == 0) {
            perpWallDist = (mapX - m_actorPosition->getPosX()
                + (1 - stepX) / 2) / m_rayProjectile->getRayDirX();
        } else {
            perpWallDist = (mapY - m_actorPosition->getPosY()
                + (1 - stepY) / 2) / m_rayProjectile->getRayDirY();
        }

        // calculate height of line to draw on screen
        qint32 lineHeight = static_cast<qint32>
            (SCENE_VIEW_HEIGHT / perpWallDist);

        // calculate lowest and highest pixel to fill in current stripe
        qint32 drawStart = -lineHeight / 2 + SCENE_VIEW_HEIGHT / 2;

        if (drawStart < 0)
            drawStart = 0;

        qint32 drawEnd = lineHeight / 2 + SCENE_VIEW_HEIGHT / 2;

        if (drawEnd >= SCENE_VIEW_HEIGHT)
            drawEnd = SCENE_VIEW_HEIGHT - 1;

        quint8 textureId = SceneMap::mapArray[mapX][mapY];

        // calculate value of wallX
        qreal wallX; // where exactly the wall was hit

        if (side == 0) {
            wallX = m_actorPosition->getPosY() + perpWallDist
                * m_rayProjectile->getRayDirY();
        } else {
            wallX = m_actorPosition->getPosX() + perpWallDist
                * m_rayProjectile->getRayDirX();
        }
        wallX -= std::floor(wallX);

        // x coordinate on the texture
        qint32 texX = static_cast<qint32>(wallX * TextureReader::textureWidth);

        if (side == 0 && m_rayProjectile->getRayDirX() > 0)
            texX = TextureReader::textureWidth - texX - 1;

        if (side == 1 && m_rayProjectile->getRayDirY() < 0)
            texX = TextureReader::textureWidth - texX - 1;

        qint32 darknessFactor = m_textureReader->calcWallDarkness(lineHeight);

        for (qint32 y = drawStart; y < drawEnd; y++) {
            // 256 and 128 factors to avoid floats
            qint32 d = y * 256 - SCENE_VIEW_HEIGHT * 128 + lineHeight * 128;
            // TODO: avoid the division to speed this up
            qint32 texY = ((d * TextureReader::textureHeight)
                / lineHeight) / 256;

            QColor textureColor = m_textureReader->getTexturePixel(textureId,
                texX, texY);

            if (side == 1) {
                m_buffer.setPixelColor(x, y,
                    textureColor.darker(darknessFactor + 50));
            } else {
                m_buffer.setPixelColor(x, y,
                    textureColor.darker(darknessFactor));
            }
        }

        // FLOOR CASTING
        // x, y position of the floor texel at the bottom of the wall
        qreal floorXWall, floorYWall;

        // 4 different wall directions possible
        if (side == 0 && m_rayProjectile->getRayDirX() > 0) {
            floorXWall = mapX;
            floorYWall = mapY + wallX;
        } else if (side == 0 && m_rayProjectile->getRayDirX() < 0) {
            floorXWall = mapX + 1.0;
            floorYWall = mapY + wallX;
        } else if (side == 1 && m_rayProjectile->getRayDirY() > 0) {
            floorXWall = mapX + wallX;
            floorYWall = mapY;
        } else {
            floorXWall = mapX + wallX;
            floorYWall = mapY + 1.0;
        }

        qreal distWall, distActor, currentDist;

        distWall = perpWallDist;
        distActor = 0.0;

        // becomes < 0 when the integer overflows
        if (drawEnd < 0)
            drawEnd = SCENE_VIEW_HEIGHT;

        // draw the floor from drawEnd to the bottom of the screen
        for (qint32 y = drawEnd + 1; y < SCENE_VIEW_HEIGHT; y++) {
            currentDist = SCENE_VIEW_HEIGHT / (2.0 * y - SCENE_VIEW_HEIGHT);

            qreal weight = (currentDist - distActor) / (distWall - distActor);

            qreal currentFloorX = weight * floorXWall + (1.0 - weight)
                * m_actorPosition->getPosX();

            qreal currentFloorY = weight * floorYWall + (1.0 - weight)
                * m_actorPosition->getPosY();

            qint32 floorTexX, floorTexY;

            floorTexX = static_cast<qint32>
                (currentFloorX * TextureReader::textureWidth)
                % TextureReader::textureWidth;

            floorTexY = static_cast<qint32>
                (currentFloorY * TextureReader::textureHeight)
                % TextureReader::textureHeight;

            qint32 darknessFactor = m_textureReader->
                calcFloorDarkness(currentDist);

            // floor
            QColor texFloorColor = m_textureReader->getTexturePixel(
                m_textureReader->getTextureFloor(), floorTexX, floorTexY);

            m_buffer.setPixelColor(x, y, texFloorColor.darker(darknessFactor));

            // ceiling
            QColor texCeilingColor = m_textureReader->getTexturePixel(
                m_textureReader->getTextureCeiling(), floorTexX, floorTexY);

            m_buffer.setPixelColor(x, SCENE_VIEW_HEIGHT - y,
                texCeilingColor.darker(darknessFactor));
        }
    }
    update();
}
