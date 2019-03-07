#ifndef AUDIOFX_H
#define AUDIOFX_H

#include <QSound>

class AudioFX
{
public:
    AudioFX(const QString &filename, int loopCount = 1);
    ~AudioFX();

    void playAudio();
    void stopAudio();

private:
    QSound *audio;
};

#endif // AUDIOFX_H
