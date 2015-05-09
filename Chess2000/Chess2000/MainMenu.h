#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#pragma once

#include <windows.h>

#include "Display.h"
#include "InputClass.h"
#include "GraphicsClass.h"
#include "Button.h"
#include "TextLabel.h"
#include <vector>

class MainMenu : public Display
{
public:
	MainMenu();
	~MainMenu();

	bool HandleInput();
	bool Update(float dt);
	bool Render();

private:
	void Play();
	void New();
	void View();
	void Exit();

	Button* mExitButton;
	Button* mPlayButton;

	std::vector<GraphicsObject*> mMenuItems;
};


#endif