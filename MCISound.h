#pragma once
class SoundData;

class MCISound : public CSingleInstance<MCISound>
{
public:
	MCISound();
	virtual ~MCISound();
public:

public:
	// ���Ϸε�
	void LoadWav(SoundData* data);
	// �÷���
	void Play(SoundData* data);
	// ����
	void Close(SoundData* data);
	// ����
	void Stop(SoundData* data);
	// ����ð� �ҷ���
	DWORD GetPos(SoundData* data);
	// `` ����
	void SetPos(SoundData* data, DWORD pos);
};

