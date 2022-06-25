#include "stdafx.h"


Animation::Animation()
{
	fTotalTime = 0.f;
	fDelay = 0.f;
	isStop = false;
	isLoop = true;
	iCurFrame = 0;
	iMaxFrame = 0;
}


Animation::~Animation()
{
}

void Animation::SetUp(LPCSTR filename, int maxFrame, float delay, bool loop)
{
	iCurFrame = 0;
	iMaxFrame = maxFrame - 1;
	fDelay = delay;
	isLoop = loop;
	isStop = false;


	for (int i = 0; i < maxFrame; i++)
	{
		char buffer[256];
		wsprintf(buffer, "%s (%d).png", filename, i + 1);
		fileNameVector.push_back(buffer);
	}

}

LPCSTR Animation::Update(float deltatime)
{
	if (isStop)
		return NULL;

	fTotalTime += deltatime;

	if (fTotalTime >= fDelay)
	{
		fTotalTime -= fDelay;
		iCurFrame++;

		if (iCurFrame > iMaxFrame)
		{
			iCurFrame = 0;
			if (!isLoop)
				isStop = true;
		}
	}

	return fileNameVector[iCurFrame].data();
}

LPCSTR Animation::UpdateLD(float deltatime)
{
	if (iCurFrame > iMaxFrame)
	{
		iCurFrame = 0;
	}
	return fileNameVector[iCurFrame].data();
}
