#include "stdafx.h"

RenderTarget::RenderTarget()
{
}


RenderTarget::~RenderTarget()
{
}

HRESULT RenderTarget::Initialize(void)
{
	LPDIRECT3DDEVICE9 pDev = CDirect3D::GetInstance()->GetDevice();
	HRESULT hr = pDev->CreateTexture(
		512, 512,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&g_pTexScene,
		NULL
	);
	if (FAILED(hr))
	{
		return E_FAIL;
	}

	g_pTexScene->GetSurfaceLevel(0, &g_pSurfScene);

	hr = pDev->CreateDepthStencilSurface(
		512, 512,
		D3DFMT_D24X8,
		D3DMULTISAMPLE_NONE,

		0,
		TRUE,
		&g_pSurfDepth,
		NULL
	);

	QuadCreate();
	return S_OK;
}

void RenderTarget::QuadCreate(void)
{
	m_dwVtxSize = sizeof(VTXSCREEN);
	m_dwVtxCnt = 4;

	LPDIRECT3DDEVICE9 pDev = CDirect3D::GetInstance()->GetDevice();

	pDev->CreateVertexBuffer(m_dwVtxSize * m_dwVtxCnt, 0, VTXFVF_SCREEN, D3DPOOL_MANAGED, &g_pVBQuad, NULL);


	VTXSCREEN*			pVtxTex = NULL;
	g_pVBQuad->Lock(0, NULL, (void**)&pVtxTex, 0);
	pVtxTex[0].vPos = D3DXVECTOR4(fX, fY, 0.f, 1.f);
	pVtxTex[0].vTexUV = D3DXVECTOR2(0.f, 0.f);

	pVtxTex[1].vPos = D3DXVECTOR4(fX + fSizeX, fY, 0.f, 1.f);
	pVtxTex[1].vTexUV = D3DXVECTOR2(1.f, 0.f);

	pVtxTex[2].vPos = D3DXVECTOR4(fX + fSizeX, fY + fSizeY, 0.f, 1.f);
	pVtxTex[2].vTexUV = D3DXVECTOR2(1.f, 1.f);

	pVtxTex[3].vPos = D3DXVECTOR4(fX, fY + fSizeY, 0.f, 1.f);
	pVtxTex[3].vTexUV = D3DXVECTOR2(0.f, 1.f);

	g_pVBQuad->Unlock();

	m_dwIdxCnt = 2;
	m_dwIdxSize = sizeof(INDEX16);

	pDev->CreateIndexBuffer(m_dwIdxSize * m_dwIdxCnt, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &g_pIBQuad, NULL);

	INDEX16*			pIndex = NULL;
	g_pIBQuad->Lock(0, 0, (void**)&pIndex, 0);

	pIndex[0]._1 = 0;
	pIndex[0]._2 = 1;
	pIndex[0]._3 = 2;

	pIndex[1]._1 = 0;
	pIndex[1]._2 = 2;
	pIndex[1]._3 = 3;

	g_pIBQuad->Unlock();
}

void RenderTarget::Render(void)
{
	LPDIRECT3DDEVICE9 pDev = CDirect3D::GetInstance()->GetDevice();
	D3DXMATRIX mIdentity;
	D3DXMatrixIdentity(&mIdentity);
	pDev->SetTransform(D3DTS_WORLD, &mIdentity);

	//pDev->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_TFACTOR);
	//pDev->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MULTIPLYADD);
	//pDev->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	//pDev->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
	//pDev->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	//pDev->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_CURRENT);
	//pDev->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	//pDev->SetTextureStageState(1, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);


	//DWORD dwTFactor = (0xFF << 24) | ((255 - 76) << 16) | ((255 - 150) << 8) | (255 - 29);
	//pDev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_DOTPRODUCT3);
	//pDev->SetRenderState(D3DRS_TEXTUREFACTOR, 50);

	pDev->SetStreamSource(0, g_pVBQuad, 0, m_dwVtxSize);
	pDev->SetFVF(VTXFVF_SCREEN);
	pDev->SetIndices(g_pIBQuad);


	pDev->SetTexture(0, g_pTexScene);
	pDev->SetTexture(1, g_pTexScene);


	pDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_dwVtxCnt, 0, m_dwIdxCnt);

}

void RenderTarget::Release(void)
{
	Safe_Release(g_pVBQuad);
	Safe_Release(g_pIBQuad);
	Safe_Release(g_pSurfOrgBB);
	Safe_Release(g_pSurfOrgDepth);
	Safe_Release(g_pSurfScene);
	Safe_Release(g_pSurfDepth);
	Safe_Release(g_pTexScene);
}

void RenderTarget::RenderTargetSceneGenerate(wstring filename)
{
	pDev = CDirect3D::GetInstance()->GetDevice();
	//pDev = pRTDev;
	//LPD3DXSPRITE	  pSprite = CDirect3D::GetInstance()->GetSprite();

	pDev->GetRenderTarget(0, &g_pSurfOrgBB);
	pDev->SetRenderTarget(0, g_pSurfScene);

	pDev->GetDepthStencilSurface(&g_pSurfOrgDepth);
	pDev->SetDepthStencilSurface(g_pSurfDepth);

	pDev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DXCOLOR(1, 0, 1, 1),
		1, 0);

	//pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pDev->BeginScene();


	//pSprite->End();
	pDev->EndScene();
	pDev->SetRenderTarget(0, g_pSurfOrgBB);
	//pDev->SetTexture(0, /*g_pTexScene*/g_pBeTexScene); 

	pDev->SetDepthStencilSurface(g_pSurfOrgDepth);
}

void RenderTarget::RenderTargetBeginGenerate(void)
{
	pDev = CDirect3D::GetInstance()->GetDevice();
	//pDev = pRTDev;
	//LPD3DXSPRITE	  pSprite = CDirect3D::GetInstance()->GetSprite();

	pDev->GetRenderTarget(0, &g_pSurfOrgBB);
	pDev->SetRenderTarget(0, g_pSurfScene);

	//pDev->GetDepthStencilSurface(&g_pSurfOrgDepth);
	//pDev->SetDepthStencilSurface(g_pSurfDepth);

	pDev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DXCOLOR(0.3f, 0.3f, 0.3f, 1), //배경, 분홍색처리. 
		1, 0);

	//pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pDev->BeginScene();
}

void RenderTarget::RenderTargetEndGenerate(void)
{
	pDev = CDirect3D::GetInstance()->GetDevice();
	//pDev = pRTDev;
	//LPD3DXSPRITE	  pSprite = CDirect3D::GetInstance()->GetSprite();

	//pSprite->End();
	pDev->EndScene();
	pDev->SetRenderTarget(0, g_pSurfOrgBB);
	//pDev->SetTexture(0, /*g_pTexScene*/g_pBeTexScene); // 이전 렌더타겟에 기록된 2D Texture 값을 

	pDev->SetDepthStencilSurface(g_pSurfOrgDepth);
}

RenderTarget * RenderTarget::Create(float fX, float fY)
{
	RenderTarget * m_pRenderTarget = new RenderTarget;
	m_pRenderTarget->fX = fX;
	m_pRenderTarget->fY = fY;
	if (FAILED(m_pRenderTarget->Initialize()))
	{
		Safe_Delete(m_pRenderTarget);
		return nullptr;
	}
	return m_pRenderTarget;
}
