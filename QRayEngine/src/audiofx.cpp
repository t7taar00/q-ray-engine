#include "audiofx.h"

AudioFX::AudioFX(const QString &filename, int loopCount)
{
    audio = new QSound(filename);
    audio->setLoops(loopCount);
}

AudioFX::~AudioFX()
{
    if(!audio->isFinished()) audio->stop();

    delete audio;
    audio = nullptr;
}

void AudioFX::playAudio()
{
    audio->play();
}

void AudioFX::stopAudio()
{
    if(!audio->isFinished()) audio->stop();
}
