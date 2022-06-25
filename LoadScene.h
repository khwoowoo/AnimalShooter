#pragma once
class LoadScene :
	public IScene
{
public:
	Sprite2D m_Background;
	Sprite2D m_LoadingImage;
	Animation m_Animation;
	LPCSTR m_FileName[256];
	Effect * m_pFadeOut;
public:
	//LoadTextureFromFile함수 사용할 더미
	Sprite2D m_LoadTexture;
public:
	//로딩할 이미지 개수
	int m_iTextureCount;
	//로딩된 이미지 개수
	int m_iTextureLDCount;
	//로딩이 완료되었는가?
	bool m_bIsLoading;
	//이미지 로딩 하나 시작하는데 시간
	float m_fLoadingTime;


	//페이드 아웃이 실행이 되었는가
	bool m_bFadeOut;
public:
	LoadScene();
	virtual ~LoadScene();
public:
	virtual void Open();
	virtual void Update(float deltatime);
	virtual void Render();
	virtual void LastRender();
	virtual void Close();
public:
	void LoadTexture(LPCSTR filename);
};

