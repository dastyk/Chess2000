#ifndef ROCK_H
#define ROCK_H

#include "Piece.h"

class Rock : public Piece
{
private:
	PlayerColor player;
	std::string type = "Rock";
	bool firstMoveDone;

public:
	~Rock();
	Rock();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);


};

#endif