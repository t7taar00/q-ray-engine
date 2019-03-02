#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#include <QImage>
#include <QColor>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

    QColor getTexturePixel(int textureId, int x, int y);

private:
    static const int textureWidth;
    static const int textureHeight;

    QImage *textureImage;
};

#endif // TEXTUREREADER_H
