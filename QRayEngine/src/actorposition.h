#ifndef ACTORPOSITION_H
#define ACTORPOSITION_H

class ActorPosition
{
public:
    ActorPosition();

    double getPosX() const;
    void setPosX(double value);

    double getPosY() const;
    void setPosY(double value);

    double getDirX() const;
    void setDirX(double value);

    double getDirY() const;
    void setDirY(double value);

    int getMapX() const;
    void setMapX(int value);

    int getMapY() const;
    void setMapY(int value);

private:
    static const double moveSpeed;
    static const double rotateSpeed;

    double posX;
    double posY;

    double dirX;
    double dirY;

    int mapX;
    int mapY;
};

#endif // ACTORPOSITION_H
