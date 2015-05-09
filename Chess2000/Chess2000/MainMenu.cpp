#include "MainMenu.h"
#include "SystemClass.h"

MainMenu::MainMenu()
{
	// Create the meny items
	mMenuItems.push_back(mPlayButton = new Button(300, 350, 200, 30, L"Play Game", 15, Color(255, 100, 100, 100)));
	mMenuItems.push_back(mExitButton = new Button(300, 400, 200, 30, L"Exit Game", 15, Color(255, 100, 100, 100)));

	mMenuItems.push_back(new TextLabel(260, 50, 300, 30, L"Chess 2000", 30, Color(0, 0, 0, 0)));
}


MainMenu::~MainMenu()
{
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		delete mMenuItems[i];
		mMenuItems[i] = 0;
	}
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
	return true;
}

bool MainMenu::Render()
{

	// Render all the meny items.
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		mMenuItems[i]->Render();
	}



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

