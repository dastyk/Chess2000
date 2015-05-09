#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
private:
	Color player;
	std::string type = "Pawn";
	bool firstMoveDone;
	

public:
	~Pawn();
	Pawn();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	Color GetColor();
	void SetColor(Color playerColor);


};




#endif