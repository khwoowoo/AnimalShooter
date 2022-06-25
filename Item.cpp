#include "stdafx.h"


Item::Item()
{
}


Item::~Item()
{
}

void Item::Init()
{
}

void Item::Render()
{
	m_Sprite.OnRender();
}

void Item::Update(float deltatime)
{
	m_Sprite.m_Position.y += m_fSpeed * deltatime;
}

void Item::Destory()
{
}

bool Item::CollisionTo(IObject * obj)
{
	if (obj->Tag == "Player")
	{
		Player * pPlayer = (Player*)obj;
		Vector3 vTemp = pPlayer->m_Sprite.m_Position - m_Sprite.m_Position;

		if (D3DXVec3Length(&vTemp) < m_fCollisionLength)
		{
			if (!isDestory)
			{
				switch (m_eItemState)
				{
				case Item::EITEM_HAERT:
					pPlayer->m_fHP += 10;
					break;
				case Item::EITEM_POWER:
					pPlayer->m_fPower += 3;
					pPlayer->WeaponChange();
					break;
				case Item::EITEM_UNIT:
					pPlayer->m_bUnit[pPlayer->m_iUnitCount] = true;
					break;
				default:
					break;
				}

				EffectGet();
				isDestory = true;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
				return true;
			}

		}
	}

	if (!isDestory)
	{
		if (m_Sprite.m_Position.x >= WinSizeX || m_Sprite.m_Position.x <= 0.f ||
			m_Sprite.m_Position.y >= WinSizeY + m_Sprite.m_Texture.info.Height * 0.5f ||
			m_Sprite.m_Position.y <= 0.f - m_Sprite.m_Texture.info.Height * 0.5f)
		{
			isDestory = true;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
			return true;
		}
	}

	return false;
}

bool Item::CollisionFrom(IObject * obj)
{
	return false;
}

void Item::SetUp(int itemImage, Vector3 pos, float speed)
{
	m_eItemState = (EITEM_STATE)itemImage;

	switch (m_eItemState)
	{
	case Item::EITEM_HAERT:
		m_Sprite.LoadTextureFromFile("Resource/Item_heart.png");
		break;
	case Item::EITEM_POWER:
		m_Sprite.LoadTextureFromFile("Resource/Item_power.png");
		break;
	case Item::EITEM_UNIT:
		m_Sprite.LoadTextureFromFile("Resource/Item_Unit.png");
		break;
	default:
		break;
	}

	m_fCollisionLength = m_Sprite.m_Texture.info.Height / 2.f;
	m_fSpeed = speed;
	m_Sprite.m_Position = pos;

}

void Item::EffectGet()
{
	Effect * pEff = new Effect;
	if (m_eItemState == EITEM_HAERT)
		pEff->Init("Resource/Item_heart.png", m_Sprite.m_Position);
	else if (m_eItemState == EITEM_POWER)
		pEff->Init("Resource/Item_power.png", m_Sprite.m_Position);
	else if (m_eItemState == EITEM_UNIT)
		pEff->Init("Resource/Item_Unit.png", m_Sprite.m_Position);
	pEff->bFadeOut = true;
	pEff->fFadeOutTime = 1.f;
	pEff->bScale = true;
	pEff->fScaleSpeed = 1.f;
	SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(pEff);
}
