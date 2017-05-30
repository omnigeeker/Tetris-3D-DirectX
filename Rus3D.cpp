// Rus3D.cpp : 定义应用程序的入口点。
//
#include "stdafx.h"
#include "Rus3D.h"
#include "Define.h"
#include "ddraw.h"
#include "var.h"
#include "Boxes.h"
#include "Show.h"
#include "Platform.h"
#include "Draw.h"
#include "DirectX.h"
#define MAX_LOADSTRING 100

// 全局变量：
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明：
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_RUS3D, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化：
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_RUS3D);

	// 主消息循环：
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数：MyRegisterClass()
//
//  目的：注册窗口类。
//
//  注释：
//
//    仅当希望在已添加到 Windows 95 的
//    “RegisterClassEx”函数之前此代码与 Win32 系统兼容时，
//    才需要此函数及其用法。调用此函数
//    十分重要，这样应用程序就可以获得关联的
//   “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_RUS3D);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCTSTR)IDC_RUS3D;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   函数：InitInstance(HANDLE, int)
//
//   目的：保存实例句柄并创建主窗口
//
//   注释：
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数：WndProc(HWND, unsigned, WORD, LONG)
//
//  目的：处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) 
	{
	case WM_CREATE:
		if( !InitDirectX(hWnd ) )
		{
			MessageBox(hWnd, TEXT("DirectX接口失败"), TEXT("ERROR"), NULL);
			CleanUp();
			SendMessage( hWnd, WM_DESTROY, 0, 0 );
		}
		Init();
		iTime = 0;
		SetTimer(hWnd,1,TIME,NULL);
		isRun = true;
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// 分析菜单选择：
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
		DrawDirectX();
		EndPaint(hWnd, &ps);
		break;
	case WM_SIZE:
		DrawDirectX();
		break;
	case WM_KEYDOWN:
		if( isRun == false )
		{
			switch( LOWORD(wParam) )
			{
			case VK_UP:
				yMe-=5;
				DrawDirectX();
				break;
			case VK_DOWN:
				yMe+=5;
				DrawDirectX();
				break;
			case VK_LEFT:
				xMe-=5;
				DrawDirectX();
				break;
			case VK_RIGHT:
				xMe+=5;
				DrawDirectX();
				break;
			case VK_TAB:
				zMe--;
				DrawDirectX();
				break;
			case VK_SPACE:
				zMe++;
				if( zMe >=-1 )
					zMe=-1;
				DrawDirectX();
				break;
			case VK_RETURN:
				iTime = 0;
				iRealTime = iTempTime;
				isRun = true;
				DrawDirectX();
				break;
			case VK_ESCAPE:
				SendMessage(hWnd, WM_DESTROY, 0, 0 );
				break;
			}
		}
		else
		{
			switch( LOWORD(wParam) )
			{
			case VK_UP:
				if( CheckUp() )
				{
					yNow--;
					DrawDirectX();
				}
				break;
			case VK_DOWN:
				if( CheckDown() )
				{
					yNow++;
					DrawDirectX();
				}
				break;
			case VK_LEFT:
				if( CheckLeft() )
				{
					xNow--;
					DrawDirectX();
				}
				break;
			case VK_RIGHT:
				if( CheckRight() )
				{
					xNow++;
					DrawDirectX();
				}
				break;
			case 'A':
				if( CheckTurn(0,offX,offY,offZ) )
				{
					swap( inT, inH);
					xNow+=offX;
					yNow+=offY;
					DrawDirectX();
				}
				break;
			case 'Z':
				if( CheckTurn(1,offX,offY,offZ) )
				{
					swap( inH, inT);
					xNow+=offX;
					yNow+=offY;
					DrawDirectX();
				}
				break;
			case 'S':
				if( CheckTurn(2,offX,offY,offZ) )
				{
					swap( inT, inV);
					xNow+=offX;
					yNow+=offY;
					zNow+=offZ;
					DrawDirectX();
				}
				break;
			case 'X':
				if( CheckTurn(3,offX,offY,offZ) )
				{
					swap( inV, inT);
					xNow+=offX;
					yNow+=offY;
					zNow+=offZ;
					DrawDirectX();
				}
			case 'D':
				if( CheckTurn(4,offX,offY,offZ) )
				{
					swap( inH, inV);
					xNow+=offX;
					yNow+=offY;
					zNow+=offZ;
					DrawDirectX();
				}
				break;
			case 'C':
				if( CheckTurn(5,offX,offY,offZ) )
				{
					swap( inV, inH);
					xNow+=offX;
					yNow+=offY;
					zNow+=offZ;
					DrawDirectX();
				}
				break;
			case VK_SPACE:
			case VK_TAB:
				iTime = 0;
				iRealTime = iFastTime;
				break;
			case VK_RETURN:
				iTime = 0;
				iRealTime = iTempTime;
				isRun = false;
				DrawDirectX();
				break;
			case VK_ESCAPE:
				SendMessage(hWnd, WM_DESTROY, 0, 0 );
				break;
			}
		}
		break;
	case WM_KEYUP:
		if( isRun )
		{
			if( LOWORD(wParam) == VK_SPACE ||  LOWORD(wParam) == VK_TAB )
			{
				iTime = 0;
				iRealTime = iTempTime;
			}
		}
		break;
	case WM_TIMER:
		if( isRun == true )
		{
			iTime++;
			if( iTime == iRealTime )
			{
				if( CheckInto() )
				{
					zNow++;
					DrawDirectX();
				}
				else
				{
					WriteNow();
					MakeDown();	
					DrawDirectX();
					iNum = _iNum;
					inV = _inV;
					inH = 2;
					inT = 1;
					_iNum = GetRand( BOXES );
					_inV = 3;	
					xNow=LCX/2;
					yNow=LCY/2;
					zNow=0;
					if( !CheckNow() )
					{
						isRun = false;
						Restart();
					}
					if( isRun )
						DrawDirectX();	
				}
				iTime=0;
			}
		}
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		CleanUp();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}
