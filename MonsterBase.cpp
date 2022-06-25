#include "stdafx.h"

MonsterBase::MonsterBase()
{
}


MonsterBase::~MonsterBase()
{
}

void MonsterBase::Move(float deltatime)
{
	switch (m_eMoveState)
	{
	case MonsterBase::EMOVE_NONE:
		break;
	case MonsterBase::EMOVE_FRONT:
		m_Sprite.m_Position.y += m_iMoveSpeed * deltatime;
		break;
	case MonsterBase::EMOVE_BACK:
		m_Sprite.m_Position.y -= m_iMoveSpeed * deltatime;
		break;
	case MonsterBase::EMOVE_LEFT:
		m_Sprite.m_Position.x += m_iMoveSpeed * deltatime;
		break;
	case MonsterBase::EMOVE_RIGHT:
		m_Sprite.m_Position.x -= m_iMoveSpeed * deltatime;
		break;
	case MonsterBase::EMOVE_LEFT_RIGHT_MOVE:
		m_Sprite.m_Position.x -= m_iMoveSpeed * deltatime * m_fDirection;

		if (m_Sprite.m_Position.x <= m_Sprite.m_Texture.info.Width ||
			m_Sprite.m_Position.x >= WinSizeX - m_Sprite.m_Texture.info.Width)
		{
			m_fDirection *= -1;
		}
		break;
	default:
		break;
	}
}

void MonsterBase::WeaponState(float deltatime)
{
	switch (m_eWeaponState)
	{
	case MonsterBase::EWEAPON_NONE:
		break;
	case MonsterBase::EWEAPON_SINGLE:
		m_fTotalShotDelay += deltatime;
		if (m_fTotalShotDelay >= m_fShotDelay)
		{
			m_fTotalShotDelay -= m_fShotDelay;

			Bullet * pAtt = new Bullet;
			pAtt->Tag = "MonsterAtt";
			pAtt->fSpeed = 800.f;
			pAtt->Init();
			pAtt->m_Sprite.m_Position = m_Sprite.m_Position;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pAtt);
		}
		break;
	case MonsterBase::EWEAPON_BARRAGE:
		m_fTotalShotDelay += deltatime;
		if (m_fTotalShotDelay >= 0.4f)
		{
			m_fTotalShotDelay -= 0.4f;

			Bullet * pAtt = new Bullet;
			pAtt->Tag = "MonsterAtt";
			pAtt->fSpeed = 800.f;
			pAtt->Init();
			pAtt->m_Sprite.m_Position = m_Sprite.m_Position;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pAtt);
		}
		break;
	case MonsterBase::EWEAPON_N_WAY:
		m_fTotalShotDelay += deltatime;
		if (m_fTotalShotDelay >= m_fShotDelay)
		{
			m_fTotalShotDelay -= m_fShotDelay;

			for (int i = 0; i < 8; ++i)
			{
				Bullet* bullet = new Bullet(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), 100 + (45 * i)));
				bullet->Tag = "MonsterAtt";
				bullet->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
			}
		}

		break;
	case MonsterBase::EWEAPON_STAGE1_MIDDLE:
		m_fTotalShotDelay += deltatime;
		if (m_fTotalShotDelay >= m_fMiddleShotDelay)
		{
			m_fTotalShotDelay -= m_fMiddleShotDelay;

			for (int i = 0; i < 16; ++i)
			{
				Bullet* bullet = new Bullet(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), 20 * i));
				bullet->Tag = "MonsterAtt";
				bullet->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
			}
		}
		break;
	case MonsterBase::EWEAPON_STAGE1_LAST:
		m_fTotalShotDelay += deltatime;
		if (m_fTotalShotDelay >= m_fLastShotDelay)
		{
			m_fTotalShotDelay -= m_fLastShotDelay;

			for (int i = 0; i < 16; ++i)
			{
				Bullet* bullet = new Bullet(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), 20 * i));
				bullet->Tag = "MonsterAtt";
				bullet->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
				//bullet->isNewAtt = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
			}

			int iRandomPos = rand() % 2 + 1;
			Bullet* bullet = new Bullet(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), 100 * iRandomPos));
			bullet->Tag = "MonsterAtt";
			bullet->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
			bullet->isNewAtt = true;
			bullet->m_Sprite.SetImageColor(25, 25, 25, 255);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
		}
		break;
	default:
		break;
	}
}

void MonsterBase::Damage(float deltatime, float Delay)
{
	Camera::GetInstance()->fShake = 200.f;
	m_fDemageTime += deltatime;
	m_fTime += deltatime / Delay * 2;
	m_Sprite.SetImageColor(255, 200, 200, (int)m_Math.Lerp(255, 0, m_fTime));

	if (m_fDemageTime >= Delay)
	{
		Camera::GetInstance()->fShake = 0.f;
		m_fDemageTime -= Delay;
		m_fTime = 0.f;
		m_Sprite.SetImageColor(255, 255, 255, 255);
		m_bDamage = false;
	}
}

void MonsterBase::DemageEffect()
{
	const DWORD iCount = 100;

	for (int i = 0; i < iCount; ++i)
	{
		float angle = rand() % 360;
		Vector3 vDest = m_Vec3Calc.Rotate(D3DXVECTOR3(0.0f, -rand() % 500 + 500, 0.0f), angle);

		Effect * pEff = new Effect;
		pEff->Init("Resource/particle.png", m_Sprite.m_Position);
		pEff->m_Physics.AddForce(vDest);
		pEff->bFadeOut = true;
		pEff->fFadeOutTime = 1.f;
		pEff->bScale = true;
		pEff->m_Sprite.SetImageColor(255, rand() % 255, rand() % 255, 255);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
	}
}

void MonsterBase::DemageEffect(float damageNumber)
{
	int aDamage[20] = { 0, };
	int fDamageNumber = (int)damageNumber;
	int iCount = 0;

	while (true)
	{
		aDamage[iCount] = fDamageNumber % 10;
		fDamageNumber /= 10;
		iCount++;

		if (fDamageNumber == 0)
			break;
	}

	float angle = rand() % 360;
	Vector3 vDest = m_Vec3Calc.Rotate(D3DXVECTOR3(0.0f, -rand() % 500 + 500, 0.0f), angle);


	for (int i = iCount - 1; i >= 0 ; i--)
	{
		Effect * pEff = new Effect;
		char buffer[256];
		wsprintf(buffer, "%s%d.png", "Resource/UI/Number/", aDamage[i]);
		pEff->Init(buffer, m_Sprite.m_Position + Vector3(100 * -i, 0.f, 0.f));
		pEff->m_Physics.AddForce(vDest);
		pEff->bScale = true;
		pEff->fScaleSpeed = 1.f;
		pEff->bFadeOut = true;
		pEff->fFadeOutTime = 1.f;
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
	}

}