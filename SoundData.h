#pragma once
class SoundData
{
public:
	SoundData();
	virtual ~SoundData();
public:

	// ���� Ÿ�� :: 
	LPCSTR fileType;
	// ���� ��ġ
	LPCSTR fileAddress;

	DWORD length;

	UINT deviceID;

	bool isLoop;
public:
	void SetFile(LPCSTR _filetype, LPCSTR _fileAddress, bool _loop);
};

