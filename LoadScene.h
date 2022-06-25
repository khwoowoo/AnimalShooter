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
	//LoadTextureFromFile�Լ� ����� ����
	Sprite2D m_LoadTexture;
public:
	//�ε��� �̹��� ����
	int m_iTextureCount;
	//�ε��� �̹��� ����
	int m_iTextureLDCount;
	//�ε��� �Ϸ�Ǿ��°�?
	bool m_bIsLoading;
	//�̹��� �ε� �ϳ� �����ϴµ� �ð�
	float m_fLoadingTime;


	//���̵� �ƿ��� ������ �Ǿ��°�
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

