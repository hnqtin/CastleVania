#include "GameSound.h"


GameSound* GameSound::instance_ = nullptr;


GameSound::GameSound()
{
}


GameSound::~GameSound()
{

	loadedSound_.clear();
}


void GameSound::initialize(HWND windowsHandler)
{
	Sound::initializeSoundClass(windowsHandler);
	instance_ = new GameSound();
}


void GameSound::play(string soundLink, bool repeat /*= false*/, bool playFromStart /*= true*/)
{
	try
	{
		if (playFromStart)
			loadedSound_.at(soundLink)->stop();
	//	stop(soundLink);

		loadedSound_.at(soundLink)->play(repeat);
	}
	catch (exception)
	{
		loadedSound_.insert(SoundPair(soundLink, new Sound(soundLink.c_str())));
		loadedSound_.at(soundLink)->play(repeat);
	}
}



GameSound* GameSound::getInstance()
{
	return instance_;
}




void GameSound::stop(string soundLink)
{
	try
	{
		loadedSound_.at(soundLink)->stop();
	}
	catch (exception)
	{

	}
}

void GameSound::Stop(int id)
{
}
