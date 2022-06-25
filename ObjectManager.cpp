#include "stdafx.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(IObject * obj)
{
	m_AddList.push_back(obj);
}

void ObjectManager::RemoveObject(IObject * obj)
{
	m_RemoveList.push_back(obj);
}

void ObjectManager::RenderAll()
{
	for (auto it : m_UpdateList)
	{
		it->Render();
	}
}

void ObjectManager::UpdateAll(float deltatime)
{
	for (auto it : m_UpdateList)
	{
		it->Update(deltatime);
	}
}

void ObjectManager::ObjectIO()
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
		{
			m_UpdateList.push_back(it);
		}
		m_AddList.clear();
	}

	if (m_UpdateList.size() > 0)
		m_UpdateList.sort(ObjectManager());
}

void ObjectManager::RemoveAll()
{
	ObjectIO();

	for (auto it : m_UpdateList)
	{
		Safe_Delete(it);
	}
	m_UpdateList.clear();
}

void ObjectManager::CollisionAll()
{
	for (auto it_to : m_UpdateList)
	{
		bool isBreak = false;
		for (auto it_from : m_UpdateList)
		{
			if (it_to->CollisionTo(it_from)) isBreak = true;
			if (it_from->CollisionFrom(it_to)) isBreak = true;
			if (isBreak) break;
		}
		if (isBreak) break;
	}
}

