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

