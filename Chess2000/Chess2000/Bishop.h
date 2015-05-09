#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
private:
	PlayerColor player;
	std::string type = "Bishop";

public:
	~Bishop();
	Bishop();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);


};

#endif