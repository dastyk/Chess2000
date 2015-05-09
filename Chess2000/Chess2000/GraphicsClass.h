////////////////////////////////////////////////////////////////////////////////
// Filename: GraphicsClass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

#pragma once

//////////////
// INCLUDES //
//////////////
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:



	bool Initialize(int, int, HWND);
	void Shutdown();
	bool BeginFrame();
	bool EndFrame();

	static GraphicsClass& GetInstance();

	void DrawString(WCHAR* text, int x, int y);

private:

	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	GraphicsClass& operator= (const GraphicsClass&);
	~GraphicsClass();

private:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	PAINTSTRUCT  mPs;
	HWND mHwnd;
	Graphics* mDevice;
};

#endif