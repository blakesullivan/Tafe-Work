#ifndef SOUNDMNG_H
#define SOUNDMNG_H

#include <SDL_mixer.h>

//#include "framework_exception.h"

#include <fstream>
#include <vector>
#include <string>
using std::string;

class SoundManager 
{
private:
	static const int audio_rate = 44100;
	static const Uint16 audio_format = AUDIO_S16;
	static const int audio_channels = 2;
	static const int audio_buffers = 4096;

	Mix_Chunk* press;
	Mix_Chunk* dice;
	Mix_Chunk* bookclose;

	Mix_Music* sapete;

	int m_iMusicVolume;

public:
	SoundManager();

	void CloseAudio();
	int InitAudio();
	void PlayMusic(string title);
	void PlayMusic(string title, int volume);
	void SetMusicVolume(int vol);
	void PlaySoundEffect(string title, int channel);
	void StopMusic();

	bool IsMusicPlaying();
};
#endif