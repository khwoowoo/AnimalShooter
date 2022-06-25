#pragma once
class ObjectManager
{
public:
	list<IObject*> m_AddList;
	list<IObject*> m_RemoveList;
	list<IObject*> m_UpdateList;
public:
	ObjectManager();
	virtual ~ObjectManager();
public:
	void AddObject(IObject * obj);
	void RemoveObject(IObject * obj);

	void RenderAll();
	void UpdateAll(float deltatime);

	void ObjectIO();
	void RemoveAll();

	void CollisionAll();

	bool operator()(IObject * layer1, IObject * layer2)
	{
		return layer1->Layer < layer2->Layer;
	}

	bool Trigger(Vector3 vec1, Vector3 vec2, float range)
	{
		Vector3 temp = vec1 - vec2;

		if (D3DXVec3Length(&temp) < range)
		{
			return true;
		}
		return false;
	}

	bool Trigger(Sprite2D * sprite1, Sprite2D * sprite2, float range)
	{
		Vector3 temp = sprite1->m_Position - sprite2->m_Position;

		if (D3DXVec3Length(&temp) < range)
		{
			return true;
		}
		return false;
	}
};

