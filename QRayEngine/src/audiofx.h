#ifndef AUDIOFX_H
#define AUDIOFX_H

#include <QtGlobal>
#include <QSound>

class AudioFX
{
public:
    AudioFX(const QString &filename, qint16 loopCount = 1);
    ~AudioFX();

    void playAudio();
    void stopAudio();

private:
    QSound *m_audio;
};

#endif // AUDIOFX_H
