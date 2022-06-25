#pragma once
class MainUI :
	public IObject
{
public:
	Sprite2D m_ScoreSprite;
	NumberSprite * m_pNumberSprite;
	Sprite2D m_SpriteTV;
public:
	MainUI();
	virtual ~MainUI();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

