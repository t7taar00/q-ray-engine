#ifndef ACTORPOSITION_H
#define ACTORPOSITION_H

#include <QtGlobal>

class ActorPosition
{
public:
    ActorPosition();

    qreal getPosX() const;
    void setPosX(qreal value);

    qreal getPosY() const;
    void setPosY(qreal value);

    qreal getDirX() const;
    void setDirX(qreal value);

    qreal getDirY() const;
    void setDirY(qreal value);

    quint8 getMapX() const;
    void setMapX(quint8 value);

    quint8 getMapY() const;
    void setMapY(quint8 value);

    static const qreal moveSpeed;
    static const qreal rotateSpeed;

private:
    qreal m_posX;
    qreal m_posY;

    qreal m_dirX;
    qreal m_dirY;

    quint8 m_mapX;
    quint8 m_mapY;
};

#endif // ACTORPOSITION_H
