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

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "graphicsclass.h"
#include "TimerClass.h"
#include "MainMenu.h"
#include "NewTournament.h"
#include "PlayGame.h"
#include "ViewTournament.h"

//Defines
#define NROFSTATES 4
#define PLAYSTATE 0
#define NEWSTATE 1
#define VIEWSTATE 2
#define MAINMENUSTATE 3


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