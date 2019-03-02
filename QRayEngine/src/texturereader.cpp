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
            textureImage->load(":/texture/greystone.png");
            break;
        case 2:
            textureImage->load(":/texture/mossy.png");
            break;
        case 3:
            textureImage->load(":/texture/wood.png");
            break;
        case 4:
            textureImage->load(":/texture/eagle.png");
            break;
        case 5:
            textureImage->load(":/texture/redbrick.png");
            break;
        case 6:
            textureImage->load(":/texture/purplestone.png");
            break;
        case TEXTURE_FLOOR:
            textureImage->load(":/texture/dungeon_floor.png");
            break;
        case TEXTURE_CEILING:
            textureImage->load(":/texture/wood_dark.png");
            break;
        default:
            break;
    }
    return textureImage->pixelColor(x, y);
}

