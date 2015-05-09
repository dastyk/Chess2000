#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState();
	~PlayState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();
};

