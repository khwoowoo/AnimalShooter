#pragma once
class IObject
{
public:
	enum EOBJECT_TYPE
	{

	};
public:
	EOBJECT_TYPE m_eObjectType;
public:
	FORCEINLINE EOBJECT_TYPE GetObjecType(void) { return m_eObjectType; }
public:
	float Layer;
	string Tag;
	bool isDestory;
public:
	IObject();
	virtual ~IObject();
public:
	virtual void Init() {};
	virtual void Render() {};
	virtual void Update(float deltatime) {};
	virtual void Destory() {};
	virtual bool CollisionTo(IObject * obj) { return false; }
	virtual bool CollisionFrom(IObject * obj) { return false; }
};

