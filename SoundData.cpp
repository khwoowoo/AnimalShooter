#include "StdAfx.h"

SoundData::SoundData()
{
	isLoop = false;
}


SoundData::~SoundData()
{
}

void SoundData::SetFile(LPCSTR _filetype, LPCSTR _fileAddress, bool _loop)
{
	fileType = _filetype;
	fileAddress = _fileAddress;
	isLoop = _loop;

	MCISound::GetInstance()->LoadWav(this);
}

