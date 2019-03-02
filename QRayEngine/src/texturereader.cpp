#include "texturereader.h"

const int TextureReader::textureWidth(64);
const int TextureReader::textureHeight(64);

TextureReader::TextureReader()
{
    textureImage = new QImage;
}

TextureReader::~TextureReader()
{
    delete textureImage;
    textureImage = nullptr;
}

QColor TextureReader::getTexturePixel(int textureId, int x, int y)
{
    switch(textureId)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 10:
        break;
    case 11:
        break;
    default:
        break;
    }
}

