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
	bool Frame();

	static GraphicsClass& GetInstance();

private:
	bool Render();

	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	GraphicsClass& operator= (const GraphicsClass&);
	~GraphicsClass();
};

#endif