////////////////////////////////////////////////////////////////////////////////
// Filename: SystemClass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

#pragma once

///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN

//////////////
// INCLUDES //
//////////////
#include <windows.h>
#include <windowsx.h>
#include <sstream>
#include <mmsystem.h>
#include <time.h>

#pragma comment( lib, "Winmm.lib" )

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "graphicsclass.h"
#include "TimerClass.h"
#include "MainMenu.h"
#include "PlayGame.h"

//Defines
#define NROFSTATES 2
#define PLAYSTATE 0
#define MAINMENUSTATE 1
#define NEWSTATE 2
#define VIEWSTATE 3



class SystemClass
{
public:


	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

	static SystemClass& GetInstance();

	void ChangeState(unsigned int state);
	void Exit();

	void ChangeCursor(LPCTSTR cursor);


private:
	bool Frame();

	bool HandleInput();
	bool Update(float dt);
	bool Render();

	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR mApplicationName;
	HINSTANCE mHinstance;
	HWND mHwnd;

	InputClass& mInput = InputClass::GetInstance();
	GraphicsClass& mGraphics = GraphicsClass::GetInstance();
	TimerClass* mTimer;

	SystemClass();
	SystemClass(const SystemClass&);
	SystemClass& operator= (const SystemClass&);
	~SystemClass();

	Display *mCurrDisplayState;

	Display* mStates[NROFSTATES];

	bool mRunning;
};

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/////////////
// GLOBALS //
/////////////
static SystemClass* ApplicationHandle = 0;

#endif