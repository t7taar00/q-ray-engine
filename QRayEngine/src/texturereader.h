#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#define TEXTURE_FLOOR 10
#define TEXTURE_CEILING 11

#include <QImage>
#include <QColor>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

    QColor getTexturePixel(int textureId, int x, int y);

    static const int textureWidth;
    static const int textureHeight;

private:
    QImage *textureImage;
};

#endif // TEXTUREREADER_H
