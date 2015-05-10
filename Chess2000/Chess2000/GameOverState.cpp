#include "GameOverState.h"
#include "PlayGame.h"

GameOverState::GameOverState()
{
	// Create the meny items
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png", -1));

	if (PlayGame::GetInstance().GetWinner() == White)
	{
		mMenuItems.push_back(new TextLabel(70, 70, 300, 30, L"White is the Winner", 45, Color(0, 0, 0, 0), -1));
	}
	else
	{
		mMenuItems.push_back(new TextLabel(70, 70, 300, 30, L"Black is the Winner", 45, Color(0, 0, 0, 0), -1));
	}

	mMenuItems.push_back(mEndButton = new Button(300, 400, 200, 30, L"End Game", 15, Color(255, 100, 100, 200), 1));

}


GameOverState::~GameOverState()
{
	GameState::~GameState();
}



bool GameOverState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool GameOverState::Render()
{
	GameState::Render();

	return true;
}


bool GameOverState::HandleInput()
{
	// Check if end button is clicked.
	if (mEndButton->IsClicked())
		End();// if clicked end game.

	return true;
}

void GameOverState::End()
{
	PlayGame::GetInstance().EndGame();
}
