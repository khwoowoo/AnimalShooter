#include "StdAfx.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::AddSound(SoundData * sound)
{
	m_AddList.push_back(sound);
}

void SoundManager::RemoveSound(SoundData * sound)
{
	m_RemoveList.push_back(sound);
}

void SoundManager::SoundIO()
{
	if (m_RemoveList.size() > 0) {
		for (auto it : m_RemoveList) {
			m_UpdateList.remove(it);
			Safe_Delete(it);
		}
		m_RemoveList.clear();
	}

	if (m_AddList.size() > 0) {
		for (auto it : m_AddList) {
			m_UpdateList.push_back(it);
		}
		m_AddList.clear();
	}
}

void SoundManager::UpdateAll()
{
	for (auto it : m_UpdateList) {
		if (it->length <= MCISound::GetInstance()->GetPos(it)) {
			if (it->isLoop) {
				MCISound::GetInstance()->SetPos(it, (DWORD)0);
				MCISound::GetInstance()->Play(it);
			}
			if (!it->isLoop) {
				RemoveSound(it);
			}
		}
	}
}

void SoundManager::RemoveAll()
{
	SoundIO();

	for (auto it : m_UpdateList) {
		MCISound::GetInstance()->Stop(it);
		MCISound::GetInstance()->Close(it);

		Safe_Delete(it);
	}
	m_UpdateList.clear();
}
