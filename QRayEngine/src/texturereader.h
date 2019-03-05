#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#define TEXTURE_FLOOR 0
#define TEXTURE_CEILING 7

#include <vector>
#include <QImage>
#include <QColor>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

    QColor getTexturePixel(unsigned int textureId, int x, int y);

    static const int textureWidth;
    static const int textureHeight;

private:
    std::vector<QImage> *textureImages;
    QImage textureImage;
};

#endif // TEXTUREREADER_H
