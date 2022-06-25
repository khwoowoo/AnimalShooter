#pragma once
class Time :
	public CSingleInstance<Time>
{
	DWORD tempFPS, FPS;
	DWORD CurrentTime, LastTime;
	DWORD TotalTime, DeltaTime;
public:
	float fDeltaTime;
public:
	bool bStop;
public:
	Time();
	virtual ~Time();
public:
	void Update();
};


