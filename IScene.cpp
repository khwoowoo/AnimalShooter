#include "stdafx.h"


IScene::IScene()
{
}


IScene::~IScene()
{
}

void IScene::SceneOpen()
{
	Open();
}

void IScene::SceneRender()
{
	Render();
	m_ObjectManager.RenderAll();
	m_EffectManager.RenderAll();
	LastRender();
	UIRender();
}

void IScene::SceneUpdate(float deltatime)
{
	Update(deltatime);
	m_ObjectManager.UpdateAll(deltatime);
	m_EffectManager.UpdateAll(deltatime);
	m_ObjectManager.CollisionAll();
	m_SoundManager.UpdateAll();
}

void IScene::SceneIO()
{
	m_ObjectManager.ObjectIO();
	m_EffectManager.ObjectIO();
	m_SoundManager.SoundIO();
}

void IScene::SceneClose()
{
	Close();
	m_ObjectManager.RemoveAll();
	m_EffectManager.RemoveAll();
	m_SoundManager.RemoveAll();
}
