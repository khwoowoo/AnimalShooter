#include "stdafx.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(LPCSTR sceneName, IScene * scene)
{
	if (m_SceneMap[sceneName] == nullptr)
	{
		m_SceneMap[sceneName] = scene;
	}
}

void SceneManager::ChangeScene(LPCSTR sceneName, bool _CloseNowScene)
{
	if (m_SceneMap[sceneName] != nullptr)
	{
		nextScene = m_SceneMap[sceneName];
		CloseNowScene = _CloseNowScene;
	}
}

void SceneManager::CheckChangeScene()
{
	if (nextScene)
	{
		if (nowScene && CloseNowScene)
			nowScene->SceneClose();

		nowScene = nextScene;
		nowScene->SceneOpen();
		nextScene = nullptr;
	}
}

void SceneManager::RemoveAll()
{
	for (auto it : m_SceneMap)
	{
		it.second->SceneClose();
		Safe_Delete(it.second);
	}
	m_SceneMap.clear();
}

IScene * SceneManager::GetScene(LPCSTR sceneName)
{
	return m_SceneMap[sceneName];
}

IScene * SceneManager::GetNowScene()
{
	return nowScene;
}
