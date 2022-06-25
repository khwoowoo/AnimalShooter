#include "stdafx.h"


Sprite2D::Sprite2D()
{
	bEnable = TRUE;
	Vector3Zero(m_Rotate);
	Vector3Zero(m_Position);
	Vector2Zero(m_RotatePivot);
	m_Scale = Vector2(1.f, 1.f);
	Vector2Zero(m_ScalePivot);
	m_Posset = Vector2(0.5f, 0.5f);
	m_Color = 0xFFFFFFFF;
	D3DXMatrixIdentity(&m_matWorld);
}

Sprite2D::Sprite2D(LPCSTR filename)
{
	this->Sprite2D::Sprite2D();
	LoadTextureFromFile(filename);
}


Sprite2D::~Sprite2D()
{
}

void Sprite2D::OnRender()
{
	if (!bEnable)
		return;

	TransformUpdate();

	// Render the vertex buffer contents
	CDirect3D::GetInstance()->GetDevice()->SetTexture(0, m_Texture.texture);
	CDirect3D::GetInstance()->GetDevice()->SetFVF(D3DFVF_CUSTOMVERTEX);
	CDirect3D::GetInstance()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2,(void*)m_VertexData, sizeof(CUSTOMVERTEX));
}

void Sprite2D::SetCustomVB()
{
	m_VertexData[0].SetVtx(0.f, 0.f, 0.f);
	m_VertexData[1].SetVtx(0.f, (float)m_Texture.info.Height, 0.f);
	m_VertexData[2].SetVtx((float)m_Texture.info.Width, 0.f, 0.f);
	m_VertexData[3].SetVtx((float)m_Texture.info.Width, (float)m_Texture.info.Height, 0.f);

	m_VertexData[0].SetColor(255, 255, 255, 255);
	m_VertexData[1].SetColor(255, 255, 255, 255);
	m_VertexData[2].SetColor(255, 255, 255, 255);
	m_VertexData[3].SetColor(255, 255, 255, 255);

	m_VertexData[0].SetUV(0.f, 0.f);
	m_VertexData[1].SetUV(0.f, 1.f);
	m_VertexData[2].SetUV(1.f, 0.f);
	m_VertexData[3].SetUV(1.f, 1.f);

}

void Sprite2D::TransformUpdate()
{
	float fX = m_Position.x;
	float fY = m_Position.y;
	float fZ = m_Position.z;

	float fPX = m_VertexData[3].pos.x;
	float fPY = m_VertexData[3].pos.y;

	float fRZ = m_Rotate.z;

	D3DXMATRIX matTrans, matPos;
	D3DXMatrixTranslation(&matTrans, fX, fY, fZ);
	D3DXMatrixTranslation(&matPos, -fPX * m_Posset.x, -fPY * m_Posset.y, 0.f);

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixTransformation2D(&matWorld, &m_ScalePivot, 0.f, &m_Scale, &m_RotatePivot, D3DXToRadian(fRZ), NULL);

	D3DXMatrixMultiply(&matWorld, &matWorld, &matPos);
	D3DXMatrixMultiply(&matWorld, &matWorld, &matTrans);

	m_matWorld = matWorld;

	CDirect3D::GetInstance()->GetDevice()->SetTransform(D3DTS_WORLD, &matWorld);

}

void Sprite2D::LoadTextureFromFile(LPCSTR filename)
{
	TextureData * temp = BitmapManager::GetInstance()->GetBitmapFile(filename);
	m_Texture.info = temp->info;
	m_Texture.texture = temp->texture;

	SetCustomVB();
}

void Sprite2D::SetImageColor(int r, int g, int b, int a)
{
	m_Color = a << 24 | r << 16 | g << 8 | b;

	m_VertexData[0].SetColor(r, g, b, a);
	m_VertexData[1].SetColor(r, g, b, a);
	m_VertexData[2].SetColor(r, g, b, a);
	m_VertexData[3].SetColor(r, g, b, a);
}

void Sprite2D::SetImageUV(float sx, float sy, float width, float height)
{
	float fX = m_Texture.info.Width;
	float fY = m_Texture.info.Height;

	m_VertexData[0].SetUV(sx / fX, sy / fY);
	m_VertexData[1].SetUV(sx / fX, (sy + height) / fY);
	m_VertexData[2].SetUV((sx + width) / fX, sy / fY);
	m_VertexData[3].SetUV((sx + width) / fX, (sy + height) / fY);
}

void Sprite2D::SetImageSize(float width, float height)
{
	m_VertexData[0].SetVtx(0.f, 0.f, 0.f);
	m_VertexData[1].SetVtx(0.f, height, 0.f);
	m_VertexData[2].SetVtx(width, 0.f, 0.f);
	m_VertexData[3].SetVtx(width, height, 0.f);
}
