#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers.
#endif

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"
#include <iostream>
#include <sstream>


#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

inline void ThrowIfFailed(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw std::exception();
	}
}


using Microsoft::WRL::ComPtr;
using namespace DirectX;

// handle to our window
HWND hwnd = NULL;

// name of our window class
LPCTSTR WindowName = "DX12_Window_Clsss";

// title of our window
LPCTSTR WindowTitle = "DirectX12 Window";

// width and height of our window
int Width = 800;
int Height = 600;

// is our window full screen?
bool FullScreen = false;


// create a window
bool InitializeWindow(HINSTANCE hInstance,
	int ShowWnd,
	int width, int height,
	bool fullscreen);

// main application loop
void mainloop();


// callback function for windows messages
LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam);