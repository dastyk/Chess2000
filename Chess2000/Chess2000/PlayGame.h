#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#pragma once
#include "Display.h"
#include "GameState.h"
#include "PickState.h"
#include "PauseState.h"
#include "PlayState.h"

#define NROFGAMESTATES 3
#define PICKSTATE 0
#define PLAYGAMESTATE 1
#define PAUSESTATE 2

class PlayGame :
	public Display
{
public:
	~PlayGame();


	bool Init();

	bool HandleInput();
	bool Update(float dt);
	bool Render();


	static void CreateInstance();
	static PlayGame* GetInstancePointer();
	static PlayGame& GetInstance();
private:
	PlayGame();
	PlayGame(const PlayGame&);
	PlayGame& operator= (const PlayGame&);


	static PlayGame* mInstance;
	

	GameState* mCurrGameState;
	GameState* mStates[NROFGAMESTATES];
};

#endif