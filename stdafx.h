#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )


#define Safe_Delete(p) {if(p){delete p;} (p) = NULL;}
#define Safe_Delete_Array(p) {if(p){delete[] p;} (p) = NULL;}
#define Safe_Release(p) {p->Release(); (p) = NULL;}

#define Vector3Zero(p) {if(p) {p = D3DXVECTOR3(0.f, 0.f, 0.f);}}
#define Vector2Zero(p) {if(p) {p = D3DXVECTOR2(0.f, 0.f);}}

const int WinSizeX = 1920;
const int WinSizeY = 1080;
const bool isWindowed = TRUE;

typedef D3DXVECTOR4 Vector4;
typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR2 Vector2;

#include <d3dx9.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <ctime>
using namespace std;

#include "Enum.h"
#include "Struct.h"
#include "SingleInstance.h"
#include "Camera.h"
#include "Direct3D.h"
#include "Time.h"
#include "BitmapManager.h"
#include "MCISound.h"
#include "SoundData.h"
#include "SoundManager.h"
#include "KeyManager.h"
#include "Sprite2D.h"
#include "IObject.h"
#include "ObjectManager.h"
#include "Animation.h"
#include "Physics.h"
#include "Effect.h"
#include "EffectManager.h"
#include "Vec3Calc.h"
#include "Math.h"

#include "IScene.h"
#include "SceneManager.h"
#include "RenderTarget.h"
//-----------------------------
#include "NumberSprite.h"
#include "MainUI.h"

#include "Button.h"

#include "Unit.h"

#include "Player.h"
#include "PlayerAtt.h"
#include "PlayerLS.h"

#include "Bullet.h"
#include "MoveBackground.h"
#include "MonsterBase.h"
#include "MonsterAlpha.h"
#include "MonsterBeta.h"
#include "MonsterGamma.h"
#include "MonsterMiddle.h"
#include "MonsterLast.h"

#include "Item.h"


#include "MonsterWave.h"

//-----------------------------
#include "Stage1.h"
#include "SceneMenu.h"
#include "LoadScene.h"
