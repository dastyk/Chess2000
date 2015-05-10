#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
private:

public:
	~Bishop();
	Bishop();
	Bishop(PlayerColor color);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};

#endif