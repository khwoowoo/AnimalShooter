#pragma once
struct CUSTOMVERTEX
{
	Vector3 pos;
	DWORD color;
	Vector2 uv;

	void SetVtx(float _x, float _y, float _z)
	{
		pos.x = _x;
		pos.y = _y;
		pos.z = _z;
	}

	void SetColor(int r, int g, int b, int a)
	{
		color = a << 24 | r << 16 | g << 8 | b;
	}

	void SetColor(DWORD _color)
	{
		color = _color;
	}

	void SetUV(float _uv, float _ux)
	{
		uv.x = _uv;
		uv.y = _ux;
	}
};

struct TextureData
{
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO  info;
};

typedef struct tagVertexUV
{
	D3DXVECTOR4			vPos;
	D3DXVECTOR2			vTexUV;
}VTXSCREEN;
const DWORD VTXFVF_SCREEN = D3DFVF_XYZRHW | D3DFVF_TEX1;

typedef struct tagIndex16
{
	WORD _1, _2, _3;
}INDEX16;