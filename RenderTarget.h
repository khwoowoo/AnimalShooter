#pragma once
class RenderTarget
{
public:
	RenderTarget();
	virtual ~RenderTarget();

public:

	LPDIRECT3DTEXTURE9	g_pTexScene = NULL;
	LPDIRECT3DSURFACE9	g_pSurfScene = NULL;
	LPDIRECT3DSURFACE9	g_pSurfDepth = NULL;

	LPDIRECT3DSURFACE9	g_pSurfOrgBB = NULL;
	LPDIRECT3DSURFACE9	g_pSurfOrgDepth = NULL;

	LPDIRECT3DVERTEXBUFFER9 g_pVBQuad = NULL;
	LPDIRECT3DINDEXBUFFER9  g_pIBQuad = NULL;

	DWORD				  m_dwVtxSize, m_dwVtxCnt;
	DWORD				  m_dwIdxSize, m_dwIdxCnt;

	LPDIRECT3DDEVICE9  pDev;

public:
	HRESULT				  Initialize(void);
	void				  QuadCreate(void);
	void				  Render(void);
	void				  Release(void);

public:
	float fX = 0.f, fY = 0.f;
	float fSizeX = 192.f * 1.7, fSizeY = 108.f * 1.7;

public:
	void				  RenderTargetSceneGenerate(wstring filename);
	void				  RenderTargetBeginGenerate(void);
	void				  RenderTargetEndGenerate(void);

public:
	static RenderTarget* Create(float fX, float fY);
};