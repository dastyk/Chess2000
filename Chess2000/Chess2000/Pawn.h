#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
private:
	PlayerColor player;
	std::string type = "Pawn";
	bool firstMoveDone;
	

public:
	~Pawn();
	Pawn();
	Pawn(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};




#endif