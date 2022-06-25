#include "stdafx.h"

void Update()
{
	SceneManager::GetInstance()->CheckChangeScene();
	CDirect3D::GetInstance()->Render();
	Time::GetInstance()->Update();
	SceneManager::GetInstance()->GetNowScene()->SceneUpdate(Time::GetInstance()->fDeltaTime);
	KeyManager::GetInstance()->Update();
	SceneManager::GetInstance()->GetNowScene()->SceneIO();
}

VOID Cleanup()
{
	SceneManager::GetInstance()->RemoveAll();
	BitmapManager::GetInstance()->RemoveAll();
	CDirect3D::GetInstance()->Cleanup();
}

//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch (msg)
	{
	case WM_MOUSEMOVE:
		KeyManager::GetInstance()->SetMousePos(LOWORD(lParam), HIWORD(lParam));
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		return 0;
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	}

    return DefWindowProc( hWnd, msg, wParam, lParam );
}

//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
    UNREFERENCED_PARAMETER( hInst );

    // Register the window class
    WNDCLASSEX wc =
    {
        sizeof( WNDCLASSEX ), CS_CLASSDC, MsgProc, 0L, 0L,
        GetModuleHandle( NULL ), NULL, NULL, NULL, NULL,
        "D3D Tutorial", NULL
    };
    RegisterClassEx( &wc );

    // Create the application's window
    HWND hWnd = CreateWindow( "D3D Tutorial", "D3D Tutorial 04: Shooting",
                              WS_POPUP|WS_EX_TOPMOST, 0, 0, WinSizeX, WinSizeY,
                              NULL, NULL, wc.hInstance, NULL );
	//WS_OVERLAPPEDWINDOW
	SetCursor(LoadCursor(NULL, IDC_ARROW));
	//SetCursor(NULL);
	//ShowCursor(FALSE);

    // Initialize Direct3D
	if (SUCCEEDED(CDirect3D::GetInstance()->InitD3D(hWnd)))
	{
		SceneManager::GetInstance()->AddScene("LoadScene", new LoadScene);
		SceneManager::GetInstance()->AddScene("SceneMenu", new SceneMenu);
		SceneManager::GetInstance()->AddScene("Stage1", new Stage1);

		SceneManager::GetInstance()->ChangeScene("LoadScene", false);

		// Show the window
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		// Enter the message loop
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
				Update();
		}

	}

    UnregisterClass(	"D3D Tutorial", wc.hInstance );
    return 0;
}