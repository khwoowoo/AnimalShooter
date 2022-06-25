#pragma once
class Animation
{
public:
	float fTotalTime;
	float fDelay;
	bool isStop, isLoop;
	int iCurFrame, iMaxFrame;
	vector<string> fileNameVector;
public:
	Animation();
	virtual ~Animation();
public:
	void SetUp(LPCSTR filename, int maxFrame, float delay, bool loop);
	LPCSTR Update(float deltatime);

	LPCSTR UpdateLD(float deltatime);
};

