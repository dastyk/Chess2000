#include "MainMenu.h"


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
	return true;
}

bool MainMenu::Update(float dt)
{
	return true;
}

bool MainMenu::Render()
{
	return true;
}



void MainMenu::Play()
{

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

