#pragma once
class KeyManager :
	public CSingleInstance<KeyManager>
{
	int KeyState[256];
	bool PrevKeyState[256];
public:
	Vector3 vMouse;
public:
	KeyManager();
	virtual ~KeyManager();

public:
	void Update();
	INT GetKeyState(int nkey);
	void SetMousePos(int x, int y);
};

