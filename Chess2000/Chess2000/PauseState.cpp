#include "PauseState.h"
#include "PlayGame.h"

PauseState::PauseState()
{
	// Create the meny items
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png"));

	mMenuItems.push_back(mContinueButton = new Button(300, 300, 200, 30, L"Continue", 15, Color(255, 100, 100, 200)));
	mMenuItems.push_back(mRestartButton = new Button(300, 350, 200, 30, L"Restart", 15, Color(255, 100, 100, 200)));
	mMenuItems.push_back(mEndButton = new Button(300, 400, 200, 30, L"End Game", 15, Color(255, 100, 100, 200)));

	mMenuItems.push_back(new TextLabel(250, 50, 300, 30, L"Chess 2000", 45, Color(0, 0, 0, 0)));
	mMenuItems.push_back(new TextLabel(255, 95, 300, 30, L"Paused", 35, Color(0, 0, 0, 0)));
}


PauseState::~PauseState()
{
	GameState::~GameState();
}



bool PauseState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool PauseState::Render()
{
	GameState::Render();

	return true;
}


bool PauseState::HandleInput()
{
	// Check if continue button is clicked.
	if (mContinueButton->IsClicked())
		Continue();// if clicked continue game.

	// Check if restart button is clicked.
	if (mRestartButton->IsClicked())
		Restart();// if clicked restart game.

	// Check if end button is clicked.
	if (mEndButton->IsClicked())
		End();// if clicked end game.

	return true;
}


void PauseState::Continue()
{
	PlayGame::GetInstance().ChangeState(PLAYGAMESTATE);
}


void PauseState::Restart()
{
	PlayGame::GetInstance().RestartGame();
}


void PauseState::End()
{
	PlayGame::GetInstance().EndGame();
}
