#include "stdafx.h"


KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

void KeyManager::Update()
{
	bool curKeyState[256];

	for (int i = 0; i < 256; i++)
	{
		curKeyState[i] = GetAsyncKeyState(i) & 0x8000;

		bool curKey = curKeyState[i];
		bool prevKey = PrevKeyState[i];

		if (prevKey == false && curKey == false) KeyState[i] = EKEY_NONE;
		else if (prevKey == false && curKey == true) KeyState[i] = EKEY_DOWN;
		else if (prevKey == true && curKey == true) KeyState[i] = EKEY_PRESS;
		else if (prevKey == true && curKey == false) KeyState[i] = EKEY_UP;

		PrevKeyState[i] = curKeyState[i];
	}
}

INT KeyManager::GetKeyState(int nkey)
{
	return KeyState[nkey];
}

void KeyManager::SetMousePos(int x, int y)
{
	vMouse = Vector3((float)x, (float)y, 0.f);
}
