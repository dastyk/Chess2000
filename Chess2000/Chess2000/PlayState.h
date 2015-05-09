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

#define RANKS 8
#define FILES 8

#define MAXMOVES 64

class PlayState :
	public GameState
{
private:
	Piece*** board;
	TextLabel* squares[RANKS][FILES];

	Pos lastPick;

	Pos validMoves[64];
	int validMoveCount;

public:
	PlayState();
	~PlayState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();



};

#endif