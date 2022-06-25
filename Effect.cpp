#include "stdafx.h"


Effect::Effect()
{
	bLife = false;
	fLifeTime = 0.f;

	bAnimation = false;

	bFadeOut = false;
	fFadeOutTime = 0.f;

	isTwinkle = false;
	fTkDelay = 0.f;
	fCurTkDelay = 0.f;

	bScale = 0.f;
	fScaleSpeed = 0.f;

	isDestroy = false;
}


Effect::~Effect()
{
}

void Effect::Init(LPCSTR filename, Vector3 pos)
{
	m_Sprite.LoadTextureFromFile(filename);
	m_Sprite.m_Position = pos;
}

void Effect::Render()
{
	m_Sprite.OnRender();
}

void Effect::Update(float deltatime)
{
	if (bLife)
	{
		fLifeTime -= deltatime;

		if (fLifeTime <= 0.f && isDestroy == false)
		{
			isDestroy = true;
			SceneManager::GetInstance()->GetNowScene()->m_EffectManager.RemoveObject(this);
			return;
		}
	}

	if (bAnimation)
	{
		LPCSTR filename = m_Animation.Update(deltatime);

		if (filename == NULL && isDestroy == false)
		{
			isDestroy = true;
			SceneManager::GetInstance()->GetNowScene()->m_EffectManager.RemoveObject(this);
			return;
		}
		m_Sprite.LoadTextureFromFile(filename);
	}

	if (bScale)
	{
		m_Sprite.m_Scale -= Vector2(fScaleSpeed * deltatime, fScaleSpeed * deltatime);

		if (m_Sprite.m_Scale.x <= 0.f && isDestroy == false)
		{
			isDestroy = true;
			SceneManager::GetInstance()->GetNowScene()->m_EffectManager.RemoveObject(this);
			return;
		}
	}

	if (bFadeOut)
	{
		D3DXCOLOR color = m_Sprite.m_Color;
		color.a -= deltatime / fFadeOutTime;
		m_Sprite.SetImageColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);

		if (color.a >= 1.f && fFadeOutTime < 0.f)
		{
			color.a = 1.f;
			m_Sprite.SetImageColor(color.r * 255, color.g * 255, color.b * 255, color.a * 255);
			bFadeOut = false;
		}

		if (fFadeOutTime > 0.f && color.a < 0.f && isDestroy == false)
		{
			fFadeOutTime = 0.f;
			bFadeOut = false;
			isDestroy = true;
			SceneManager::GetInstance()->GetNowScene()->m_EffectManager.RemoveObject(this);
			return;
		}
	}

	if (isTwinkle)
	{
		fCurTkDelay += deltatime;
		if (fCurTkDelay > fTkDelay)
		{
			m_Sprite.bEnable = !m_Sprite.bEnable;
			fCurTkDelay -= fTkDelay;
		}
	}

	m_Sprite.m_Position = m_Physics.Update(m_Sprite.m_Position, deltatime);
}
