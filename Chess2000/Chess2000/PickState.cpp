#include "PickState.h"

#include "SystemClass.h"
#include "PlayGame.h"

PickState::PickState()
{

	// Create the meny items
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png", -1));

	mMenuItems.push_back(mStartButton = new Button(300, 350, 200, 30, L"Start Game", 15, Color(200, 100, 100, 200), 1));
	mMenuItems.push_back(mMenuButton = new Button(300, 400, 200, 30, L"Main Menu", 15, Color(200, 100, 100, 200), 1));

	mMenuItems.push_back(new TextLabel(250, 50, 300, 30, L"Chess 2000", 45, Color(0, 0, 0, 0), -1));
	mMenuItems.push_back(new TextLabel(255, 95, 300, 30, L"Play", 35, Color(0, 0, 0, 0), -1));
}


PickState::~PickState()
{
	GameState::~GameState();
}

bool PickState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool PickState::Render()
{
	GameState::Render();

	return true;
}


bool PickState::HandleInput()
{
	// Check if menu button is clicked.
	if (mMenuButton->IsClicked())
		SystemClass::GetInstance().ChangeState(MAINMENUSTATE);// if clicked go to menu.

	// Check if start button is clicked.
	if (mStartButton->IsClicked())
		StartGame();// if clicked start the game.


	return true;
}

void PickState::StartGame()
{
	PlayGame::GetInstance().StartGame();
}
