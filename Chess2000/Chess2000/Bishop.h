#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
private:
	Color player;
	std::string type = "Bishop";

public:
	~Bishop();
	Bishop();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	Color GetColor();
	void SetColor(Color playerColor);


};

#endif