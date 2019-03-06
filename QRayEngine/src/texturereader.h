#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#include <vector>
#include <QImage>
#include <QColor>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

    QColor getTexturePixel(uint textureId, int x, int y);

    uint getTextureFloor() const;
    uint getTextureCeiling() const;

    int calcWallDarkness(int lineHeight);      // TODO: currently just for testing,
    int calcFloorDarkness(double currentDist); // fix these awful functions in future

    static const int textureWidth;
    static const int textureHeight;

private:
    uint textureFloor;
    uint textureCeiling;

    std::vector<QImage> *textureImages;
    QImage textureImage;
};

#endif // TEXTUREREADER_H
