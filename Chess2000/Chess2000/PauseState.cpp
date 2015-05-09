#include "PauseState.h"


PauseState::PauseState()
{
}


PauseState::~PauseState()
{
}



bool PauseState::Update(float dt)
{
	return true;
}


bool PauseState::Render()
{
	return true;
}


bool PauseState::HandleInput()
{
	return true;
}


void PauseState::Continue()
{
}


void PauseState::Restart()
{
}


void PauseState::End()
{
}
