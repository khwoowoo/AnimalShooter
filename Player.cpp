#include "stdafx.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Init()
{
	Tag = "Player";
	m_Sprite.LoadTextureFromFile("Resource/airpalne.png");
	m_Sprite.m_Position = Vector3(960.f, 1000.f, 0.f);
	//m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
	m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
	m_Sprite.m_ScalePivot = Vector2(150.f, 150.f);
	m_ePlayerState = EPLAYER_NONE;
	m_eWeaponState = EWEAPON_SINGLE;

	m_HPBar.LoadTextureFromFile("Resource/UI/HealthBar.png");
	m_HPBar.SetImageColor(255, 255, 255, 200);
	m_HPBar.m_Position = Vector3(400.f, 1000.f, 0.f);

	m_iKillMonster = 0;

	m_WeaponStateSprite.LoadTextureFromFile("Resource/UI/waepon_one.png");
	m_WeaponStateSprite.m_Posset = Vector2(0.f, 0.f);
	m_WeaponStateSprite.m_Position = Vector3(WinSizeX - m_WeaponStateSprite.m_Texture.info.Width, 135.f, 0.f);


}

void Player::Render()
{
	m_WeaponStateSprite.OnRender();
	m_Sprite.OnRender();
	m_HPBar.OnRender();

}

void Player::Update(float deltatime)
{
	m_Sprite.m_Position = m_Physics.Update(m_Sprite.m_Position, deltatime);

	Move(deltatime);
	PlayerState(deltatime);
	WeaponState(deltatime);

	if (m_bDamage == true)
		Damage(deltatime, 2.f);
	//데미지 
	m_HPBar.m_Scale = Vector2(max(m_fHP / m_fMaxHP, 0), 1.f);

	//유닛생성
	UnitCreate();

}

void Player::Destory()
{
}

bool Player::CollisionTo(IObject * obj)
{
	//공격 받음
	if (obj->Tag == "MonsterAtt")
	{
		Bullet * m_pAtt = (Bullet*)obj;
		Vector3 vTemp = m_pAtt->m_Sprite.m_Position - m_Sprite.m_Position;
		if (D3DXVec3Length(&vTemp) < 50.f)
		{
			DemageEffect();
			DemageEffect(m_pAtt->fPower);
			if (!m_pAtt->isDestory)
			{
				m_pAtt->isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(m_pAtt);
				cout << "MonsterAlpha공격으로 인한 적의 총알 삭제" << endl;
			}
			m_fHP -= m_pAtt->fPower;
			m_bDamage = true;
			return true;
		}
	}
	return false;
}

bool Player::CollisionFrom(IObject * obj)
{
	return false;
}

void Player::Move(float deltatime)
{
	if (KeyManager::GetInstance()->GetKeyState(VK_UP) == EKEY_PRESS)
	{
		m_Sprite.m_Position.y -= m_iMoveSpeed * deltatime;

		Effect * eEff = new Effect;
		eEff->Init("Resource/airpalne.png", m_Sprite.m_Position);
		eEff->m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
		eEff->m_Sprite.m_ScalePivot = Vector2(150.f, 150.f);
		eEff->bFadeOut = true;
		eEff->fFadeOutTime = 0.1f;
		if (m_bDamage == true)
			eEff->m_Sprite.SetImageColor(255, 200, 200, 120);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(eEff);

		m_ePlayerState = EPLAYER_UP;
	}
	if (KeyManager::GetInstance()->GetKeyState(VK_DOWN) == EKEY_PRESS)
	{
		m_Sprite.m_Position.y += m_iMoveSpeed * deltatime;

		Effect * eEff = new Effect;
		eEff->Init("Resource/airpalne.png", m_Sprite.m_Position);
		eEff->m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
		eEff->m_Sprite.m_ScalePivot = Vector2(150.f, 150.f);
		eEff->bFadeOut = true;
		eEff->fFadeOutTime = 0.1f;
		if (m_bDamage == true)
			eEff->m_Sprite.SetImageColor(255, 200, 200, 120);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(eEff);

		m_ePlayerState = EPLAYER_DOWN;
	}
	if (KeyManager::GetInstance()->GetKeyState(VK_LEFT) == EKEY_PRESS)
	{
		m_Sprite.m_Position.x -= m_iMoveSpeed * deltatime;

		Effect * eEff = new Effect;
		eEff->Init("Resource/airpalne.png", m_Sprite.m_Position);
		eEff->m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
		eEff->m_Sprite.m_ScalePivot = Vector2(150.f, 150.f);
		eEff->bFadeOut = true;
		eEff->fFadeOutTime = 0.1f;
		if (m_bDamage == true)
			eEff->m_Sprite.SetImageColor(255, 200, 200, 120);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(eEff);

		m_ePlayerState = EPLAYER_LEFT;
	}
	if (KeyManager::GetInstance()->GetKeyState(VK_RIGHT) == EKEY_PRESS)
	{
		m_Sprite.m_Position.x += m_iMoveSpeed * deltatime;

		Effect * eEff = new Effect;
		eEff->Init("Resource/airpalne.png", m_Sprite.m_Position);
		eEff->m_Sprite.m_Scale = Vector2(0.5f, 0.5f);
		eEff->m_Sprite.m_ScalePivot = Vector2(150.f, 150.f);
		eEff->bFadeOut = true;
		eEff->fFadeOutTime = 0.1f;
		if (m_bDamage == true)
			eEff->m_Sprite.SetImageColor(255, 200, 200, 120);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(eEff);

		m_ePlayerState = EPLAYER_RIGHT;
	}

	if (KeyManager::GetInstance()->GetKeyState(VK_RIGHT) == EKEY_UP ||
		KeyManager::GetInstance()->GetKeyState(VK_LEFT) == EKEY_UP ||
		KeyManager::GetInstance()->GetKeyState(VK_DOWN) == EKEY_UP ||
		KeyManager::GetInstance()->GetKeyState(VK_UP) == EKEY_UP )
	{
		m_ePlayerState = EPLAYER_NONE;
	}

	if (m_Sprite.m_Position.x >= WinSizeX - 150.f * 0.5f)
		m_Sprite.m_Position.x = WinSizeX - 150.f * 0.5f;
	if (m_Sprite.m_Position.x <= 150.f * 0.5f)
		m_Sprite.m_Position.x = 150.f * 0.5f;
	if (m_Sprite.m_Position.y <= 150.f * 0.5f)
		m_Sprite.m_Position.y = 150.f * 0.5f;
	if (m_Sprite.m_Position.y >= WinSizeY - 150.f * 0.5f)
		m_Sprite.m_Position.y = WinSizeY - 150.f * 0.5f;
}

void Player::PlayerState(float deltatime)
{
	switch (m_ePlayerState)
	{
	case Player::EPLAYER_NONE:
		break;
	case Player::EPLAYER_UP:
		break;
	case Player::EPLAYER_DOWN:
		break;
	case Player::EPLAYER_LEFT:
		break;
	case Player::EPLAYER_RIGHT:
		break;
	case Player::EPLAYER_ATT:

		break;
	default:
		break;
	}
}

void Player::WeaponState(float deltatime)
{
	if (m_bAttSound)
	{
		//SoundData* sound = new SoundData;
		//sound->SetFile("WaveAudio", "Resource/laser.wav", false);
		//SceneManager::GetInstance()->GetNowScene()->m_SoundManager.AddSound(sound);
		//MCISound::GetInstance()->Play(sound);
		PlaySound("Resource/sound4.wav", NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP);
		m_bAttSound = false;
	}

	if (KeyManager::GetInstance()->GetKeyState(VK_F1) == EKEY_DOWN)
	{
		WeaponChange();

		//m_bDamage = !m_bDamage;
		m_fHP += 10.f;
	}

	switch (m_eWeaponState)
	{
	case Player::EWEAPON_SINGLE:
		if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_DOWN)
		{
			m_bAttSound = true;


			PlayerAtt * pAtt = new PlayerAtt;
			pAtt->Init();
			pAtt->fPower = m_fPower;
			pAtt->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pAtt);
		}
		break;
	case Player::EWEAPON_BARRAGE:
		if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_PRESS)
		{
			m_bAttSound = true;

			m_fTotalShotDelay += deltatime;
			if (m_fTotalShotDelay >= m_fShotDelay)
			{
				m_fTotalShotDelay -= m_fShotDelay;
				//PlaySound("Resource/sound1.wav", NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP);

				PlayerAtt * pAtt = new PlayerAtt;
				pAtt->Init();
				pAtt->fPower = m_fPower;
				pAtt->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pAtt);
			}
		}
		break;
	case Player::EWEAPON_TREEWAY:
		if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_DOWN)
		{
			m_bAttSound = true;

			for (int i = 0; i < 3; ++i)
			{
				PlayerAtt * bullet = new PlayerAtt(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), -15 + (15 * i)));
				bullet->fPower = m_fPower;
				bullet->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
			}
		}
		break;
	case Player::EWEAPON_LASER:
		if (KeyManager::GetInstance()->GetKeyState(VK_SPACE) == EKEY_PRESS)
		{
			PlayerLS * pLaser = new PlayerLS;
			pLaser->m_Player = this;
			pLaser->Init();
			pLaser->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pLaser);
		}
		break;
	default:
		break;
	}
}

void Player::Damage(float deltatime, float Delay)
{
	m_fDamageTime += deltatime;
	//m_fDemageTime -= 1.f;
	m_fTime += deltatime / Delay * 2;;
	m_Sprite.SetImageColor(255, 200, 200, (int)m_Math.Lerp(255, 0, m_fTime));

	if (m_fDamageTime >= Delay)
	{
		m_fDamageTime -= Delay;
		m_fTime = 0.f;
		m_Sprite.SetImageColor(255, 255, 255, 255);
		m_bDamage = false;
	}
}

void Player::DemageEffect()
{
	const DWORD iCount = 100;

	for (int i = 0; i < iCount; ++i)
	{
		float angle = rand() % 360;
		Vector3 vDest = Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -rand() % 500 + 500, 0.0f), angle);

		Effect * pEff = new Effect;
		pEff->Init("Resource/particle.png", m_Sprite.m_Position);
		pEff->m_Physics.AddForce(vDest);
		pEff->bFadeOut = true;
		pEff->fFadeOutTime = 1.f;
		pEff->bScale = true;
		pEff->m_Sprite.SetImageColor(25, 25, rand() % 255, 255);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
	}

	Effect * pEff = new Effect;
	pEff->Init("Resource/Damage.png", Vector3(0.f, 0.f, 0.f));
	pEff->m_Sprite.m_Posset = Vector2(0.f, 0.f);
	pEff->bFadeOut = true;
	pEff->fFadeOutTime = 1.f;
	SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
}

void Player::DemageEffect(float damageNumber)
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
	Vector3 vDest = Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -rand() % 500 + 500, 0.0f), angle);


	for (int i = iCount; i > 0; i--)
	{
		Effect * pEff = new Effect;
		char buffer[256];
		wsprintf(buffer, "%s%d.png", "Resource/UI/Number/", aDamage[i]);
		pEff->Init(buffer, m_Sprite.m_Position + Vector3(100 * i, 0.f, 0.f));
		pEff->m_Physics.AddForce(vDest);
		pEff->bFadeOut = true;
		pEff->fFadeOutTime = 1.f;
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
	}

}

void Player::UnitCreate()
{
	if (m_iUnitCount < 4)
	{
		if (m_bUnit[m_iUnitCount])
		{
			m_pUnit[m_iUnitCount] = new Unit;
			m_pUnit[m_iUnitCount]->Init();
			m_pUnit[m_iUnitCount]->m_pPlayer = this;
			if (m_iUnitCount == 0)
				m_pUnit[m_iUnitCount]->AddPositiom = Vector3(-130.f, 50.f, 0.f);
			else if (m_iUnitCount == 1)
				m_pUnit[m_iUnitCount]->AddPositiom = Vector3(130.f, 50.f, 0.f);
			else if (m_iUnitCount == 2)
				m_pUnit[m_iUnitCount]->AddPositiom = Vector3(-260.f, 100.f, 0.f);
			else if (m_iUnitCount == 3)
				m_pUnit[m_iUnitCount]->AddPositiom = Vector3(260.f, 100.f, 0.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pUnit[m_iUnitCount]);
			m_bUnit[m_iUnitCount] = false;
			m_iUnitCount++;
		}
	}
}

void Player::WeaponChange()
{
	if ((EWEAPON_STATE)m_iNextWeapon == int(sizeof(EWEAPON_STATE)) - 1)
		m_iNextWeapon = -1;
	m_iNextWeapon++;
	m_eWeaponState = (EWEAPON_STATE)m_iNextWeapon;

	switch (m_eWeaponState)
	{
	case Player::EWEAPON_SINGLE:
		m_WeaponStateSprite.LoadTextureFromFile("Resource/UI/waepon_one.png");
		break;
	case Player::EWEAPON_BARRAGE:
		m_WeaponStateSprite.LoadTextureFromFile("Resource/UI/waepon_two.png");
		break;
	case Player::EWEAPON_TREEWAY:
		m_WeaponStateSprite.LoadTextureFromFile("Resource/UI/waepon_three.png");
		break;
	case Player::EWEAPON_LASER:
		m_WeaponStateSprite.LoadTextureFromFile("Resource/UI/waepon_four.png");
		break;
	default:
		break;
	}

}