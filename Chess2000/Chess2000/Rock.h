#ifndef ROCK_H
#define ROCK_H

#include "Piece.h"

class Rock : public Piece
{
private:
	Color player;
	std::string type = "Rock";
	bool firstMoveDone;

public:
	~Rock();
	Rock();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	Color GetColor();
	void SetColor(Color playerColor);


};

#endif