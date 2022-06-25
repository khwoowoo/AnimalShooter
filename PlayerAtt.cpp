#include "stdafx.h"


PlayerAtt::PlayerAtt()
{
}

PlayerAtt::PlayerAtt(Vector3 direction)
{
	Init();
	m_Direction = direction;
	m_Sprite.m_Rotate.z = Vec3Calc::Angle(Vector3(0.f, -1.f, 0.f), direction);
}


PlayerAtt::~PlayerAtt()
{
}

void PlayerAtt::Init()
{
	Tag = "PlayerAtt";
	m_Direction = Vector3(0.f, -fSpeed, 0.f);
	m_Sprite.LoadTextureFromFile("Resource/att1.png");
	m_Sprite.m_Scale = Vector2(0.7f, 0.7f);
	m_Sprite.m_ScalePivot = Vector2(m_Sprite.m_Texture.info.Width * 0.7f, m_Sprite.m_Texture.info.Height * 0.7f);
}

void PlayerAtt::Render()
{
	m_Sprite.OnRender();
}

void PlayerAtt::Update(float deltatime)
{
	m_Sprite.m_Position += m_Direction * deltatime;

	//Effect * eEff = new Effect;
	//eEff->Init("Resource/att.png", m_Sprite.m_Position);
	//eEff->m_Sprite.m_Scale = Vector2(0.7f, 0.7f);
	//eEff->m_Sprite.m_ScalePivot = Vector2(m_Sprite.m_Texture.info.Width * 0.7f, m_Sprite.m_Texture.info.Height * 0.7f);
	//eEff->bFadeOut = true;
	//eEff->fFadeOutTime = 0.1f;
	//SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(eEff);

	if (m_Sprite.m_Position.y <= 0.f && !isDestory)
	{
		isDestory = true;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		cout << "player의 공격 삭제 완료" << endl;
	}
}

void PlayerAtt::Destory()
{
}

bool PlayerAtt::CollisionTo(IObject * obj)
{
	return false;
}

bool PlayerAtt::CollisionFrom(IObject * obj)
{
	return false;
}