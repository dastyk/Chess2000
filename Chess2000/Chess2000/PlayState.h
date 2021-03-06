#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_



#pragma once
#include "GameState.h"
#include "Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rock.h"
#include "King.h"

#include "TextLabel.h"
#include "TextListClass.h"
#include "PopUpClass.h"

#include "Move.h"
#include "Button.h"

#include <sstream>

#define RANKS 8
#define FILES 8

#define MAXMOVES 64

class PlayState :
	public GameState
{
private:
	Piece*** board;
	TextLabel* squares[RANKS][FILES];
	TextListClass* lastMoveList;
	std::vector<Move*> lastMoves;


	Pos lastPick;

	Pos validMoves[64];
	int validMoveCount;

	PlayerColor currPlayer;

	PopUpClass* mPawnAtEndPop;
	Pos mPawnAtEnd;

	Button* mPauseButton;
	Button* mSurrenderButton;


	void WaitForPopAnswer();
	void PieceIsPawn(Pos e);
	void RecordMove(Pos e);
	void Deselect();

public:
	PlayState();
	~PlayState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();



};

#endif