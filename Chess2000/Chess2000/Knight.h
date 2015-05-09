#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
private:
	PlayerColor player;
	std::string type = "Knight";

public:
	~Knight();
	Knight();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);


};

#endif