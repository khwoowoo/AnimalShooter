#pragma once
class SoundManager
{
public:
	SoundManager();
	virtual ~SoundManager();

private:
	list<SoundData*> m_AddList;
	list<SoundData*> m_UpdateList;
	list<SoundData*> m_RemoveList;
public:
	void AddSound(SoundData* sound);
	void RemoveSound(SoundData* sound);

	void SoundIO();

	void UpdateAll();
	void RemoveAll();
};

