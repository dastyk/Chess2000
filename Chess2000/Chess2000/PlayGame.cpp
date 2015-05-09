#include "PlayGame.h"

PlayGame* PlayGame::mInstance = nullptr;

PlayGame::PlayGame()
{
	mCurrGameState = nullptr;
	for (unsigned int i = 0; i < NROFGAMESTATES; i++)
	{
		mStates[i] = nullptr;
	}

}


PlayGame::~PlayGame()
{
	Display::~Display();
	for (unsigned int i = 0; i < NROFGAMESTATES; i++)
	{
		if (mStates[i])
		{
			delete mStates[i];
			mStates[i] = nullptr;
		}
		
	}
}

bool PlayGame::Init()
{
	// Create the pick and the pause state objects.
	mStates[PICKSTATE] = new PickState();
	if (!mStates[PICKSTATE])
	{
		return false;
	}
	mStates[PAUSESTATE] = new PauseState();
	if (!mStates[PAUSESTATE])
	{
		return false;
	}

	// Set to the default game state.
	mCurrGameState = mStates[PICKSTATE];

	return true;
}

bool PlayGame::HandleInput()
{
	bool result;

	result = mCurrGameState->HandleInput();
	if (!result)
	{
		return false;
	}

	return true;
}

bool PlayGame::Update(float dt)
{
	bool result;

	result = mCurrGameState->Update(dt);
	if (!result)
	{
		return false;
	}

	return true;
}

bool PlayGame::Render()
{
	bool result;

	result = mCurrGameState->Render();
	if (!result)
	{
		return false;
	}

	return true;
}

void PlayGame::CreateInstance()
{
	if (!mInstance)
	{
		static PlayGame* inst = new PlayGame();
		mInstance = inst;

	}

}

PlayGame*  PlayGame::GetInstancePointer()
{
	return mInstance;
}


PlayGame&  PlayGame::GetInstance()
{
	return *mInstance;
}

void PlayGame::ChangeState(UINT state)
{
	mCurrGameState = mStates[state];
}

void PlayGame::StartGame()
{
	mCurrGameState = mStates[PLAYGAMESTATE] = new PlayState();
}
