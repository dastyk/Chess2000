#ifndef _GAMEOVERSTATE_H_
#define _GAMEOVERSTATE_H_

#pragma once
#include "GameState.h"
#include "Button.h"
#include "TextLabel.h"
#include "ImageClass.h"

class GameOverState :
	public GameState
{
public:
	GameOverState();
	~GameOverState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();
private:

	void End();

	Button* mEndButton;
};

#endif