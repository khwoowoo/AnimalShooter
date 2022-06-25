#include "stdafx.h"

MonsterBeta::MonsterBeta()
{
}


MonsterBeta::~MonsterBeta()
{
}

void MonsterBeta::Init()
{
	Tag = "MonsterBeta";

	m_iScore = 103;

	m_eKindState = EKIND_BETA;
	m_isSpriteOpecity = false;
	m_HPBar.LoadTextureFromFile("Resource/UI/HealthBar.png");
	m_HPBar.SetImageColor(255, 255, 255, 200);
}

void MonsterBeta::Render()
{
	m_Sprite.OnRender();
	m_HPBar.OnRender();
}

void MonsterBeta::Update(float deltatime)
{
	Move(deltatime);

	//체력바 위치
	m_HPBar.m_Position = m_Sprite.m_Position + Vector3(m_HPBar.m_Texture.info.Width * 0.25f, (m_HPBar.m_Texture.info.Height * 0.7f) * -1.f, 0.f);

	//데미지 
	if (m_bDamage == true)
		Damage(deltatime, 1.f);
	m_HPBar.m_Scale = Vector2(max(m_fHP / m_fMaxHP, 0) * 0.5f, 0.5f);

	WeaponState(deltatime);

	if (m_isSpriteOpecity)
		m_Sprite.SetImageColor(255, 255, 255, 200);
}

void MonsterBeta::Destory()
{
}

bool MonsterBeta::CollisionTo(IObject * obj)
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
				cout << "내가 MonsterBeta공격으로 인한 플레이어총알 삭제" << endl;
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
				cout << "내가 MonsterBeta공격으로 인한 플레이어레이져 삭제" << endl;
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
				cout << "MonsterBeta 거리 죽음" << endl;
				return true;
			}
			else if (m_fHP <= 0.f)
			{
				pPlayer->m_iKillMonster++;
				pPlayer->m_iScore += m_iScore;
				isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
				Dead_Ability();
				cout << "MonsterBeta 체력 죽음" << endl;
				return true;
			}
		}

	}
	return false;
}

bool MonsterBeta::CollisionFrom(IObject * obj)
{
	return false;
}

void MonsterBeta::SetUp(LPCSTR filename, Vector3 Pos, int eMoveState, int eWeaponState, float speed, int AbilityPossibleCount)
{
	Init();
	m_iAbilityPossibleCount = AbilityPossibleCount;
	m_Sprite.LoadTextureFromFile(filename);
	m_Sprite.m_Position = Pos;
	m_eMoveState = (EMOVE_STATE)eMoveState;
	m_iFirstMoveState = eMoveState;
	m_eWeaponState = (EWEAPON_STATE)eWeaponState;
	m_iMoveSpeed = speed;
	m_fDamage = m_Sprite.m_Texture.info.Width * 0.5f;
}

void MonsterBeta::Dead_Ability()
{
	if (m_iAbilityPossibleCount > 0)
	{
		MonsterBeta * mb = new MonsterBeta;
		mb->SetUp("Resource/monsterBeta.png", m_Sprite.m_Position + Vector3(-200.f, 0.f, 0.f), 1, 3, 200.f, m_iAbilityPossibleCount - 1);
		mb->m_iScore = (int)(m_iScore / 2);
		mb->m_isSpriteOpecity = true;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mb);

		MonsterBeta * mb1 = new MonsterBeta;
		mb1->SetUp("Resource/monsterBeta.png", m_Sprite.m_Position + Vector3(200.f, 0.f, 0.f), 1, 3, 200.f, m_iAbilityPossibleCount -1);
		mb1->m_iScore = (int)(m_iScore / 2);
		mb1->m_isSpriteOpecity = true;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mb1);
	}

}
