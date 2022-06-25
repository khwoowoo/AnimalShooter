#pragma once
class IScene
{
public:
	ObjectManager m_ObjectManager;
	EffectManager m_EffectManager;
	SoundManager m_SoundManager;
public:
	IScene();
	virtual ~IScene();
public:
	void SceneOpen();
	void SceneRender();
	void SceneUpdate(float deltatime);
	void SceneIO();
	void SceneClose();

	virtual void Open() {};
	virtual void Update(float deltatime) {};
	virtual void Render() {};
	virtual void LastRender() {};
	virtual void RenderTargetRender() {};
	virtual void Close() {};
	virtual void UIRender() {};
};
/*
Stage1 * m_pStage1_1 = nullptr;
for (auto it: SceneManager::GetInstance()->m_SceneMap)
{
if (it.second->m_eSceneType == ESCENE_STAGE1)
m_pStage1_1 = dynamic_cast<Stage1*>(it.second);
*/

