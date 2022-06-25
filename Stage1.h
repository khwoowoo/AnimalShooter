#pragma once
class Stage1 :
	public IScene
{
public:
	Player * m_pPlayer;
	MonsterAlpha * m_pMonsterAlpha;
	MainUI * m_pMainUI;
	MonsterWave * m_pMonsterWave;
	RenderTarget * m_pRenderTarget;
	SoundData* background1;
	Sprite2D m_ResultUI;
	Button * m_pButton[3];
public:
	bool m_bWinUI;
	bool m_bLoseUI;
public:
	Stage1();
	virtual ~Stage1();
public:
	virtual void Open();
	virtual void Update(float deltatime);
	virtual void Render();
	virtual void RenderTargetRender();
	virtual void UIRender();
	virtual void LastRender();
	virtual void Close();
public:
	void LoseUI();
	void WinUI();
};

