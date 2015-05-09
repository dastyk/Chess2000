#include "PlayState.h"


PlayState::PlayState()
{
	
}


PlayState::~PlayState()
{
	GameState::~GameState();
}

bool PlayState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool PlayState::Render()
{
	GameState::Render();

	return true;
}


bool PlayState::HandleInput()
{
	return true;
}