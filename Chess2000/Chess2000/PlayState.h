#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#pragma once
#include "GameState.h"
#include "Button.h"
#include "ImageClass.h"

class PlayState :
	public GameState
{
public:
	PlayState();
	~PlayState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();

private:
};

#endif