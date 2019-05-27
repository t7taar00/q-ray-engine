#ifndef SCENEMAP_H
#define SCENEMAP_H

#define MAP_WIDTH 48
#define MAP_HEIGHT 48

#include <QtGlobal>

class SceneMap
{
public:
    static const quint8 mapArray[MAP_WIDTH][MAP_HEIGHT];
};

#endif // SCENEMAP_H
