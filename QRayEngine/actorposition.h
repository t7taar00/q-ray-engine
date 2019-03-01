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

private:
    double posX;
    double posY;
    double dirX;
    double dirY;
};

#endif // ACTORPOSITION_H
