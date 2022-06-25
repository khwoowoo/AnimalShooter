#pragma once
class Button :
	public IObject
{
public:
	Sprite2D m_Sprite;
public:
	float m_fTouchLen = 0.f;
	bool m_bTouchBig = false;
	bool m_bClick = false;
	bool m_bIn = false;
public:
	Button();
	virtual ~Button();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void SetUp(LPCSTR filename, Vector3 Pos, float len, bool big);
};

