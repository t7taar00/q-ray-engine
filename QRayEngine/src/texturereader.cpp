#include "texturereader.h"

const int TextureReader::textureWidth(64);
const int TextureReader::textureHeight(64);

TextureReader::TextureReader()
{
    textureImage = new QImage(textureWidth, textureHeight, QImage::Format_RGB32);
    textureImage->load(":/texture/texture/dungeon_floor.png");
}

TextureReader::~TextureReader()
{
    delete textureImage;
    textureImage = nullptr;
}

QColor TextureReader::getTexturePixel(int textureId, int x, int y)
{
    /*switch(textureId)
    {
        case 1:
            textureImage->load(":/texture/texture/greystone.png");
            break;
        case 2:
            textureImage->load(":/texture/texture/mossy.png");
            break;
        case 3:
            textureImage->load(":/texture/texture/wood.png");
            break;
        case 4:
            textureImage->load(":/texture/texture/eagle.png");
            break;
        case 5:
            textureImage->load(":/texture/texture/redbrick.png");
            break;
        case 6:
            textureImage->load(":/texture/texture/purplestone.png");
            break;
        case TEXTURE_FLOOR:
            textureImage->load(":/texture/texture/dungeon_floor.png");
            break;
        case TEXTURE_CEILING:
            textureImage->load(":/texture/texture/wood_dark.png");
            break;
        default:
            break;
    }*/
    return textureImage->pixelColor(x, y);
}

