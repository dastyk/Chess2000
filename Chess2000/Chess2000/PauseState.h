#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#pragma once
#include "GameState.h"
#include "Button.h"
#include "TextLabel.h"
#include "ImageClass.h"

class PauseState :
	public GameState
{
public:
	PauseState();
	~PauseState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();
private:
	void Continue();
	void Restart();
	void End();

	Button* mContinueButton;
	Button* mRestartButton;
	Button* mEndButton;
};

#endif