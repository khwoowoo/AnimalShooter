#pragma once
class SoundData
{
public:
	SoundData();
	virtual ~SoundData();
public:

	// 파일 타입 :: 
	LPCSTR fileType;
	// 파일 위치
	LPCSTR fileAddress;

	DWORD length;

	UINT deviceID;

	bool isLoop;
public:
	void SetFile(LPCSTR _filetype, LPCSTR _fileAddress, bool _loop);
};

