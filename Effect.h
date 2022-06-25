#pragma once
class Effect
{
public:
	Sprite2D m_Sprite;
	Animation m_Animation;
	Physics m_Physics;
public:
	bool bLife;
	float fLifeTime;

	bool bAnimation;

	bool bFadeOut;
	float fFadeOutTime;

	bool bScale;
	float fScaleSpeed;

	bool isTwinkle;
	float fTkDelay;
	float fCurTkDelay;

	bool isDestroy;

public:
	Effect();
	virtual ~Effect();
public:
	virtual void Init() {};
	virtual void Init(LPCSTR filename, Vector3 pos);
	virtual void Render();
	virtual void Update(float deltatime);
};

