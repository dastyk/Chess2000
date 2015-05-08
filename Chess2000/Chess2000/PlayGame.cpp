#include "PlayGame.h"

PlayGame* PlayGame::mInstance = nullptr;

PlayGame::PlayGame()
{
}


PlayGame::~PlayGame()
{
}

bool PlayGame::HandleInput()
{
	GoToMainMenu();

	return true;
}

bool PlayGame::Update(float dt)
{
	return true;
}

bool PlayGame::Render()
{
	return true;
}

void PlayGame::CreateInstance()
{
	static PlayGame* inst = new PlayGame();
	mInstance = inst;
}

PlayGame*  PlayGame::GetInstancePointer()
{
	return mInstance;
}


PlayGame&  PlayGame::GetInstance()
{
	return *mInstance;
}