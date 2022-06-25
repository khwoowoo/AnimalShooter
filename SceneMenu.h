#pragma once
class SceneMenu :
	public IScene
{
public:
	Sprite2D m_Background;
	Button * m_pButton[2];
	SoundData* background1;
public:
	SceneMenu();
	virtual ~SceneMenu();
public:
	virtual void Open();
	virtual void Update(float deltatime);
	virtual void Render();
	virtual void LastRender();
	virtual void Close();
};

