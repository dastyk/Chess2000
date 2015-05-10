#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
private:
	

public:
	~Pawn();
	Pawn();
	Pawn(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);


};




#endif