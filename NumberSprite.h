#pragma once
class NumberSprite
{
public:
	Sprite2D m_Sprite[10];
	Vector3 m_Position;
	string m_NumberText;
public:
	float m_fOneSize;
	int m_iR, m_iG, m_iB, m_iA;
public:
	NumberSprite();
	virtual ~NumberSprite();
public:
	//�����̹����� ũ��(���� ������ ����)
	void Init();
	void SetOneNumber(float size);
	void SetPosition(float x, float y);
	void SetColor(int r, int g, int b, int a);
	void SetNumber(string number);
	void SetNumber(int number);
	void Render();
};

