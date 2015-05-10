#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#pragma once
#include "Display.h"
#include "GameState.h"
#include "PickState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "GameOverState.h"

#define NROFGAMESTATES 4
#define PICKSTATE 0
#define PLAYGAMESTATE 1
#define PAUSESTATE 2
#define GAMEOVERSTATE 3

class PlayGame :
	public Display
{
public:
	~PlayGame();


	bool Init();

	bool HandleInput();
	bool Update(float dt);
	bool Render();

	void ChangeState(UINT state);
	void StartGame();
	void EndGame();
	void EndGameKingTaken(PlayerColor currentPlayer);
	void RestartGame();

	void SetWinner(PlayerColor currentPlayer);
	PlayerColor GetWinner();

	static void CreateInstance();
	static PlayGame* GetInstancePointer();
	static PlayGame& GetInstance();


private:
	PlayGame();
	PlayGame(const PlayGame&);
	PlayGame& operator= (const PlayGame&);


	static PlayGame* mInstance;
	
	PlayerColor winner;

	GameState* mCurrGameState;
	GameState* mStates[NROFGAMESTATES];
};

#endif