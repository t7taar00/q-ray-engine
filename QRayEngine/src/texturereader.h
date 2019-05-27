#ifndef TEXTUREREADER_H
#define TEXTUREREADER_H

#include <QtGlobal>
#include <QImage>
#include <QColor>

#include <vector>

class TextureReader
{
public:
    TextureReader();
    ~TextureReader();

    QColor getTexturePixel(quint8 textureId, qint32 x, qint32 y);

    quint8 getTextureFloor() const;
    quint8 getTextureCeiling() const;

    qint32 calcWallDarkness(qint32 lineHeight);  // TODO: currently just for testing,
    qint32 calcFloorDarkness(qreal currentDist); // fix these awful functions in future

    static const quint8 textureWidth;
    static const quint8 textureHeight;

private:
    quint8 m_textureFloor;
    quint8 m_textureCeiling;

    std::vector<QImage> *m_textureImages;
    QImage m_textureImage;
};

#endif // TEXTUREREADER_H
