#include "stdafx.h"


BitmapManager::BitmapManager()
{
}


BitmapManager::~BitmapManager()
{
}

void BitmapManager::RemoveAll()
{
	for (auto it : m_TextureMap)
	{
		Safe_Release(it.second->texture);
		Safe_Delete(it.second);
	}
	m_TextureMap.clear();
}

void BitmapManager::LoadBitmapFile(LPCSTR filename)
{
	if (m_TextureMap[filename] == nullptr)
	{
		TextureData * temp = new TextureData;
		temp->texture = CDirect3D::GetInstance()->LoadTextureFromFile(filename, &temp->info);
		m_TextureMap[filename] = temp;
	}
}

TextureData * BitmapManager::GetBitmapFile(LPCSTR filename)
{
	if (m_TextureMap[filename] == nullptr)
		LoadBitmapFile(filename);

	return m_TextureMap[filename];
}
