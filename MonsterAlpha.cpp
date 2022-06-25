#include "stdafx.h"


MonsterAlpha::MonsterAlpha()
{
}


MonsterAlpha::~MonsterAlpha()
{
}

void MonsterAlpha::Init()
{
	Tag = "MonsterAlpha";

	m_iScore = 75;

	m_fHP = 50.f;

	m_eKindState = EKIND_ALPHA;

	m_HPBar.LoadTextureFromFile("Resource/UI/HealthBar.png");
	m_HPBar.SetImageColor(255, 255, 255, 200);
}

void MonsterAlpha::Render()
{
	m_Sprite.OnRender();
	m_HPBar.OnRender();
}

void MonsterAlpha::Update(float deltatime)
{
	Move(deltatime);

	//체력바 위치
	m_HPBar.m_Position = m_Sprite.m_Position + Vector3(m_HPBar.m_Texture.info.Width * 0.25f, (m_HPBar.m_Texture.info.Height * 0.7f) * -1.f, 0.f);

	//데미지 
	if (m_bDamage == true)
		Damage(deltatime, 1.f);
	m_HPBar.m_Scale = Vector2(max(m_fHP / m_fMaxHP, 0) * 0.5f, 0.5f);

	WeaponState(deltatime);
}

void MonsterAlpha::Destory()
{
}

bool MonsterAlpha::CollisionTo(IObject * obj)
{

	if (obj->Tag == "Player")
	{
		//어쩌다 보니 밀리기가 됨.
		//Player * player = (Player*)obj;
		//Vector3 vTemp = player->m_Sprite.m_Position - m_Sprite.m_Position;
		//Vector3 vTemp1 = m_Sprite.m_Position - vTemp;
		//if (D3DXVec3Length(&vTemp) < 100.f)
		//{
		//	m_eMoveState = EMOVE_NONE;
		//	m_Sprite.m_Position = vTemp1;
		//}

	}

	//공격 받음
	if (obj->Tag == "PlayerAtt")
	{
		PlayerAtt * m_pAtt = (PlayerAtt*)obj;
		Vector3 vTemp = m_pAtt->m_Sprite.m_Position - m_Sprite.m_Position;
		if (D3DXVec3Length(&vTemp) < m_fDamage)
		{
			DemageEffect();
			DemageEffect(m_pAtt->fPower);
			if (!m_pAtt->isDestory)
			{
				m_pAtt->isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(m_pAtt);
				cout << "내가 MonsterAlpha공격으로 인한 플레이어총알 삭제" << endl;
			}
			m_fHP -= m_pAtt->fPower;
			m_bDamage = true;
			return true;
		}
	}
	if (obj->Tag == "PlayerLS")
	{
		PlayerLS * m_pAtt = (PlayerLS*)obj;
		Vector3 vTemp = m_pAtt->m_Sprite.m_Position - m_Sprite.m_Position;
		if (D3DXVec3Length(&vTemp) < m_fDamage)
		{
			if (!m_pAtt->isDestory)
			{
				m_pAtt->isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(m_pAtt);
				cout << "내가 MonsterAlpha공격으로 인한 플레이어레이져 삭제" << endl;
			}
			m_fHP -= m_pAtt->fPower;
			m_bDamage = true;
			return true;
		}
	}

	if (obj->Tag == "Player")
	{
		Player * pPlayer = (Player*)obj;

		//죽음
		if (!isDestory)
		{
			if (m_Sprite.m_Position.x >= WinSizeX || m_Sprite.m_Position.x <= 0.f ||
				m_Sprite.m_Position.y >= WinSizeY + m_Sprite.m_Texture.info.Height * 0.5f ||
				m_Sprite.m_Position.y <= 0.f - m_Sprite.m_Texture.info.Height * 0.5f)
			{
				isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
				cout << "MonsterAlpha 범위 죽음" << endl;
				return true;
			}
			else if (m_fHP <= 0.f)
			{
				pPlayer->m_iKillMonster++;
				pPlayer->m_iScore += m_iScore;
				isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
				cout << "MonsterAlpha 체력 죽음" << endl;
				return true;
			}
		}
	}

	return false;
}

bool MonsterAlpha::CollisionFrom(IObject * obj)
{
	return false;
}

void MonsterAlpha::SetUp(LPCSTR filename, Vector3 Pos, int eMoveState, int eWeaponState, float speed)
{
	Init();
	m_Sprite.LoadTextureFromFile(filename);
	m_Sprite.m_Position = Pos;
	m_eMoveState = (EMOVE_STATE)eMoveState;
	m_iFirstMoveState = eMoveState;
	m_eWeaponState = (EWEAPON_STATE)eWeaponState;
	m_iMoveSpeed = speed;
	m_fDamage = m_Sprite.m_Texture.info.Width * 0.5f;
}