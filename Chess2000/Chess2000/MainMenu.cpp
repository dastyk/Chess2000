#include "MainMenu.h"
#include "SystemClass.h"

MainMenu::MainMenu()
{

	// Create the meny items
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png"));

	mMenuItems.push_back(mPlayButton = new Button(300, 350, 200, 30, L"Play Game", 15, Color(255, 100, 100, 200)));
	mMenuItems.push_back(mExitButton = new Button(300, 400, 200, 30, L"Exit Game", 15, Color(255, 100, 100, 200)));

	mMenuItems.push_back(new TextLabel(250, 50, 300, 30, L"Chess 2000", 45, Color(0, 0, 0, 0)));
	mMenuItems.push_back(new TextLabel(255, 95, 300, 30, L"Main Menu", 35, Color(0, 0, 0, 0)));

	
}


MainMenu::~MainMenu()
{
	Display::~Display();
}


bool MainMenu::HandleInput()
{
	// Check if exit button is clicked.
	if (mExitButton->IsClicked())
		Exit(); // if clicked exit application.

	// Check if play button is clicked.
	if (mPlayButton->IsClicked())
	{
		Play(); // if clicked switch to PlayGame.
	}

	return true;
}

bool MainMenu::Update(float dt)
{
	Display::Update(dt);


	return true;
}

bool MainMenu::Render()
{
	Display::Render();

	return true;
}



void MainMenu::Play()
{
	// Change to PlayGame state
	SystemClass::GetInstance().ChangeState(PLAYSTATE);
}


void MainMenu::New()
{

}


void MainMenu::View()
{
	// Change to ViewTurnament state
	SystemClass::GetInstance().ChangeState(NEWSTATE);
}


void MainMenu::Exit()
{
	// Exit the application.
	SystemClass::GetInstance().Exit();
}

