#pragma once
class SoundData;

class MCISound : public CSingleInstance<MCISound>
{
public:
	MCISound();
	virtual ~MCISound();
public:

public:
	// 파일로드
	void LoadWav(SoundData* data);
	// 플레이
	void Play(SoundData* data);
	// 삭제
	void Close(SoundData* data);
	// 정지
	void Stop(SoundData* data);
	// 재생시간 불러옴
	DWORD GetPos(SoundData* data);
	// `` 설정
	void SetPos(SoundData* data, DWORD pos);
};

