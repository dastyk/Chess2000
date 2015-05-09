#ifndef _PICKSTATE_H_
#define _PICKSTATE_H_

#pragma once
#include "GameState.h"
#include "Button.h"
#include <vector>

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

	std::vector<GraphicsObject*> mMenuItems;
};

#endif