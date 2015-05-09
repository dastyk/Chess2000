#include "MainMenu.h"
#include "SystemClass.h"

MainMenu::MainMenu()
{

}


MainMenu::~MainMenu()
{
}


bool MainMenu::HandleInput()
{
	// Check if the user pressed escape and wants to exit the application.
	if (mInput.IsKeyDown(VK_ESCAPE))
	{
		Exit();
	}
	// Check if user pressed the return key and wants to change to view tournament state.
	if (mInput.IsKeyDown(VK_RETURN))
	{
		View();
	}
	// Check if user pressed the F1 key and wants to change to play game state.
	if (mInput.IsKeyDown(VK_F1))
	{
		Play();
	}

	if (mInput.IsMouseKeyDown(LMOUSE))
	{
		Exit();
	}

	return true;
}

bool MainMenu::Update(float dt)
{
	return true;
}

bool MainMenu::Render()
{
	mGraphics.DrawString(L"MAIN FUCKING MENU BITCHES!!!!", 50, 50);
	mGraphics.DrawString(L"PLAY THE FUCKING GAME", 50, 75);
	mGraphics.DrawString(L"EXIT THE FUCKING GAME", 50, 100);
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

