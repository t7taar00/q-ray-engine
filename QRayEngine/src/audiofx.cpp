#include "audiofx.h"

AudioFX::AudioFX(const QString &filename, qint16 loopCount)
{
    m_audio = new QSound(filename);
    m_audio->setLoops(loopCount);
}

AudioFX::~AudioFX()
{
    stopAudio();

    delete m_audio;
    m_audio = nullptr;
}

void AudioFX::playAudio()
{
    m_audio->play();
}

void AudioFX::stopAudio()
{
    if (!m_audio->isFinished())
        m_audio->stop();
}
