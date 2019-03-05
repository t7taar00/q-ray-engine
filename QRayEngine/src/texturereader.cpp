#include "texturereader.h"

const int TextureReader::textureWidth(64);
const int TextureReader::textureHeight(64);

TextureReader::TextureReader()
{
    textureImages = new std::vector<QImage>;
    textureImage = QImage(textureWidth, textureHeight, QImage::Format_RGB32);

    textureImage.load(":/texture/texture/dungeon_floor.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/greystone.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/mossy.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/wood.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/eagle.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/redbrick.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/purplestone.png");
    textureImages->push_back(textureImage);

    textureImage.load(":/texture/texture/wood_dark.png");
    textureImages->push_back(textureImage);
}

TextureReader::~TextureReader()
{
    delete textureImages;
    textureImages = nullptr;
}

QColor TextureReader::getTexturePixel(unsigned int textureId, int x, int y)
{
    return textureImages->at(textureId).pixelColor(x, y);
}

