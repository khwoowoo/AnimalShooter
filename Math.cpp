#include "stdafx.h"


Math::Math()
{
}


Math::~Math()
{
}

float Math::Lerp(float start, float end, float time)
{
	return start - time * (end - start);
}
