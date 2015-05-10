#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
private:


public:
	~Knight();
	Knight();
	Knight(PlayerColor color);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);


};

#endif