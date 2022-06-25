#include "StdAfx.h"

MCISound::MCISound()
{
}


MCISound::~MCISound()
{
}

void MCISound::LoadWav(SoundData * data)
{
	MCI_OPEN_PARMS mciOpen;

	mciOpen.lpstrDeviceType = data->fileType;
	mciOpen.lpstrElementName = data->fileAddress;

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)&mciOpen);

	data->deviceID = mciOpen.wDeviceID;

	MCI_STATUS_PARMS mciStatus;
	mciStatus.dwItem = MCI_STATUS_LENGTH;
	mciSendCommand(data->deviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);

	data->length = mciStatus.dwReturn;

}

void MCISound::Play(SoundData* data)
{
	MCI_PLAY_PARMS mciPlay;
	mciSendCommand(data->deviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
}


void MCISound::Close(SoundData * data)
{
	MCI_GENERIC_PARMS mciGeneric;
	mciSendCommand(data->deviceID, MCI_PAUSE, MCI_WAIT, (DWORD)&mciGeneric);
	mciSendCommand(data->deviceID, MCI_CLOSE, NULL, NULL);
}

void MCISound::Stop(SoundData * data)
{
	MCI_GENERIC_PARMS mciGeneric;
	mciSendCommand(data->deviceID, MCI_STOP, MCI_WAIT, (DWORD)&mciGeneric);
}

DWORD MCISound::GetPos(SoundData * data)
{
	MCI_STATUS_PARMS mciStatus;
	mciStatus.dwItem = MCI_STATUS_POSITION;
	mciSendCommand(data->deviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);

	return mciStatus.dwReturn;
}

void MCISound::SetPos(SoundData * data, DWORD pos)
{
	MCI_SEEK_PARMS mciSeek;
	mciSeek.dwTo = pos;
	mciSendCommand(data->deviceID, MCI_SEEK, MCI_TO, (DWORD)&mciSeek);
}
