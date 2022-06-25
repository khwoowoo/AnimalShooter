#include "stdafx.h"


Time::Time()
{
	CurrentTime = timeGetTime();

	tempFPS = 0;
	FPS = 0;

	DeltaTime = 0;
	TotalTime = 0;

	fDeltaTime = 0.f;

	LastTime = CurrentTime;

	bStop = false;
}


Time::~Time()
{
}

void Time::Update()
{
	CurrentTime = timeGetTime();

	DeltaTime = CurrentTime - LastTime;
	fDeltaTime = DeltaTime / 1000.f;
	if (bStop)
		fDeltaTime = 0.f;

	++tempFPS;
	TotalTime += DeltaTime;
	if (TotalTime >= 1000)
	{
		FPS = tempFPS;
		tempFPS = 0;

		TotalTime -= 1000;
	}

	LastTime = CurrentTime;
}
