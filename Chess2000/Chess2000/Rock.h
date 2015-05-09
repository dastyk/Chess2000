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
	Rock(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};

#endif