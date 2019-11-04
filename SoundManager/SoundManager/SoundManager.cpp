#include "SoundManager.h"

//Constructors
SoundManager::SoundManager() 
{
	m_iMusicVolume = 100;

	press = NULL;
	dice = NULL;
	bookclose = NULL;

	sapete = NULL;
}

//Private
//

//Public
void SoundManager::CloseAudio() 
{
	Mix_FreeChunk(press);
	Mix_FreeChunk(dice);
	Mix_FreeChunk(bookclose);

	Mix_HaltMusic();
	Mix_FreeMusic(sapete);

	Mix_CloseAudio();
}

int SoundManager::InitAudio() 
{
	int i = Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers);

	if (!i) 
	{
		press = Mix_LoadWAV("sounds/Btn1.wav");
		dice = Mix_LoadWAV("sounds/Btn5.wav");
		bookclose = Mix_LoadWAV("sounds/BookClse.wav");

		sapete = Mix_LoadMUS("sounds/music/Che_Sapete_Che_Cosa_E_Amor.wav");
	}
	
	return i;
}

void SoundManager::PlayMusic(string title) 
{
	if (title == "sapete") 
	{
		Mix_PlayMusic(sapete, -1);
		Mix_VolumeMusic(m_iMusicVolume);
	}
	else 
	{
		//Framework_Exception fe("Unknown music file: " + title);
		//throw fe;
	}
}

void SoundManager::PlayMusic(string title, int volume) 
{
	PlayMusic(title);
	SetMusicVolume(volume);
}

void SoundManager::SetMusicVolume(int vol) 
{
	Mix_VolumeMusic(vol);
	m_iMusicVolume = vol;
}

void SoundManager::PlaySoundEffect(string title, int channel) 
{
	if (title == "press") 
		{Mix_PlayChannel(channel, press, 0);}
	else if (title == "dice") 
		{Mix_PlayChannel(channel, dice, 0);}
	else if (title == "bookclose") 
		{Mix_PlayChannel(channel, bookclose, 0);}
	else 
	{
		//Framework_Exception fe("Unknown soundfx file: " + title);
		//throw fe;
	}
}

void SoundManager::StopMusic() 
{
	Mix_HaltMusic();
}

bool SoundManager::IsMusicPlaying() 
{
	if (Mix_PlayingMusic()) 
		{return true;}
	else 
		{return false;}
}