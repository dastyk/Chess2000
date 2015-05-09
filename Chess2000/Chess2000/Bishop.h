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
	Bishop(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};

#endif