#include "NewTournament.h"


NewTournament::NewTournament()
{

}


NewTournament::~NewTournament()
{
}


bool NewTournament::HandleInput()
{
	// Check if the user pressed escape and wants to exit the application.
	if (mInput.IsKeyDown(VK_SPACE))
	{
		GoToMainMenu();
	}

	return true;
}

bool NewTournament::Update(float dt)
{
	return true;
}

bool NewTournament::Render()
{
	return true;
}
