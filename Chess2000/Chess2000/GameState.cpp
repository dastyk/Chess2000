#include "GameState.h"


GameState::GameState()
{
}


GameState::~GameState()
{
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		delete mMenuItems[i];
		mMenuItems[i] = 0;
	}
}


bool GameState::Update(float dt)
{
	return true;
}


bool GameState::Render()
{

	// Render all the meny items.
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		mMenuItems[i]->Render();
	}


	return true;
}


bool GameState::HandleInput()
{
	return true;
}
