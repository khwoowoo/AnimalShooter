#pragma once
class EffectManager
{
public:
	list<Effect*> m_AddList;
	list<Effect*> m_RemoveList;
	list<Effect*> m_UpdateList;
public:
	EffectManager();
	virtual ~EffectManager();
public:
	void AddObject(Effect * obj);
	void RemoveObject(Effect * obj);

	void RenderAll();
	void UpdateAll(float deltatime);

	void ObjectIO();
	void RemoveAll();
};

