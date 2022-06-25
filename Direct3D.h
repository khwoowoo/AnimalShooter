#pragma once
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX2)

class CDirect3D :
	public CSingleInstance<CDirect3D>
{
public:
	LPDIRECT3D9             g_pD3D = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device
public:
	FORCEINLINE LPDIRECT3DDEVICE9 GetDevice(void) { return g_pd3dDevice; }
public:
	CDirect3D();
	virtual ~CDirect3D();
public:
	HRESULT InitD3D(HWND hWnd);
	VOID Cleanup();
	VOID SetupMatrices();
	VOID Render();
	LPDIRECT3DTEXTURE9 LoadTextureFromFile(LPCSTR filename, D3DXIMAGE_INFO * info);
};

