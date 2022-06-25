#include "stdafx.h"


EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}

void EffectManager::AddObject(Effect * obj)
{
	m_AddList.push_back(obj);
}

void EffectManager::RemoveObject(Effect * obj)
{
	m_RemoveList.push_back(obj);
}

void EffectManager::RenderAll()
{
	for (auto it : m_UpdateList)
	{
		it->Render();
	}
}

void EffectManager::UpdateAll(float deltatime)
{
	for (auto it : m_UpdateList)
	{
		it->Update(deltatime);
	}
}

void EffectManager::ObjectIO()
{
	if (m_RemoveList.size() > 0)
	{
		for (auto it : m_RemoveList)
		{
			m_UpdateList.remove(it);
			Safe_Delete(it);
		}
		m_RemoveList.clear();
	}

	if (m_AddList.size() > 0)
	{
		for (auto it : m_AddList)
			m_UpdateList.push_back(it);

		m_AddList.clear();
	}
}

void EffectManager::RemoveAll()
{
	ObjectIO();

	for (auto it : m_UpdateList)
	{
		Safe_Delete(it);
	}
	m_UpdateList.clear();
}
