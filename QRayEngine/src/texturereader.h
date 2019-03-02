#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#include <QImage>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

private:
    static const int textureWidth;
    static const int textureHeight;

    QImage *textureImage;
};

#endif // TEXTUREREADER_H
