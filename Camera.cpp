#include "stdafx.h"
	

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::SetupMatrices(float deltatime)
{
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	CDirect3D::GetInstance()->GetDevice()->SetTransform(D3DTS_VIEW, &matView);

	DWORD halfX = WinSizeX * 0.5f;
	DWORD halfY = WinSizeY * 0.5f;

	RECT rect;
	rect.left =   (halfX - halfX / fScale) + (fShake * deltatime);
	rect.right =  (halfX + halfX / fScale) -(fShake * deltatime);
	rect.top =    (halfY - halfY / fScale) + (fShake * deltatime);
	rect.bottom = (halfY + halfY / fScale) - (fShake * deltatime);


	D3DXMatrixOrthoOffCenterLH(&matProj, rect.left, rect.right, rect.bottom, rect.top, 0.1f,100.0f);
	CDirect3D::GetInstance()->GetDevice()->SetTransform(D3DTS_PROJECTION, &matProj);

}

void Camera::SetPos(Vector3 pos)
{
	vLookatPt = pos;
	vEyePt.x = pos.x;
	vEyePt.y = pos.y;
}

Vector3 Camera::GetPos() const
{
	return vLookatPt;
}
