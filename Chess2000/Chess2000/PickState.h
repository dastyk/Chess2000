#ifndef _PICKSTATE_H_
#define _PICKSTATE_H_

#pragma once
#include "GameState.h"
#include "Button.h"
#include "ImageClass.h"

class PickState :
	public GameState
{
public:
	PickState();
	~PickState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();
private:
	void StartGame();

	Button* mMenuButton;
	Button* mStartButton;


};

#endif