#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
private:
	Color player;
	std::string type = "Knight";

public:
	~Knight();
	Knight();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	Color GetColor();
	void SetColor(Color playerColor);


};

#endif