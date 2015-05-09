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


class PlayState :
	public GameState
{
private:
	Piece* board[RANKS][FILES];


public:
	PlayState();
	~PlayState();


	bool Update(float dt);
	bool Render();
	bool HandleInput();
};

#endif