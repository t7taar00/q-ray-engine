#include "texturereader.h"

const quint8 TextureReader::textureWidth(64);
const quint8 TextureReader::textureHeight(64);

TextureReader::TextureReader()
    : m_textureFloor(0)
{
    m_textureImages = new std::vector<QImage>;
    m_textureImage = QImage(textureWidth, textureHeight, QImage::Format_RGB32);

    m_textureImage.load(":/texture/texture/dungeon_floor.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/greystone.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/mossy.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/wood.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/eagle.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/redbrick.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/purplestone.png");
    m_textureImages->push_back(m_textureImage);

    m_textureImage.load(":/texture/texture/wood_dark.png");
    m_textureImages->push_back(m_textureImage);

    m_textureCeiling = static_cast<quint8>(m_textureImages->size() - 1);
}

TextureReader::~TextureReader()
{
    delete m_textureImages;
    m_textureImages = nullptr;
}

QColor TextureReader::getTexturePixel(quint8 textureId, qint32 x, qint32 y)
{
    return m_textureImages->at(textureId).pixelColor(x, y);
}

quint8 TextureReader::getTextureFloor() const
{
    return m_textureFloor;
}

quint8 TextureReader::getTextureCeiling() const
{
    return m_textureCeiling;
}

qint32 TextureReader::calcWallDarkness(qint32 lineHeight)
{
    qint32 darknessFactor = 600 - lineHeight * 2;
    if (darknessFactor < 80)
        darknessFactor = 80;

    return darknessFactor;
}

qint32 TextureReader::calcFloorDarkness(qreal currentDist)
{
    qint32 darknessFactor = static_cast<qint32>(currentDist * 50);
    if (darknessFactor < 80)
        darknessFactor = 80;

    return darknessFactor;
}

