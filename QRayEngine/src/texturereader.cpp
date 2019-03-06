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

    textureFloor = 0;
    textureCeiling = static_cast<uint>(textureImages->size() - 1);
}

TextureReader::~TextureReader()
{
    delete textureImages;
    textureImages = nullptr;
}

QColor TextureReader::getTexturePixel(uint textureId, int x, int y)
{
    return textureImages->at(textureId).pixelColor(x, y);
}

uint TextureReader::getTextureFloor() const
{
    return textureFloor;
}

uint TextureReader::getTextureCeiling() const
{
    return textureCeiling;
}

int TextureReader::calcWallDarkness(int lineHeight)
{
    int darknessFactor = 600 - lineHeight * 2;
    if(darknessFactor < 80) darknessFactor = 80;

    return darknessFactor;
}

int TextureReader::calcFloorDarkness(double currentDist)
{
    int darknessFactor = static_cast<int>(currentDist * 50);
    if(darknessFactor < 80) darknessFactor = 80;

    return darknessFactor;
}

