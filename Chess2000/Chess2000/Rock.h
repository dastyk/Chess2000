#ifndef ROCK_H
#define ROCK_H

#include "Piece.h"

class Rock : public Piece
{
private:

	bool firstMoveDone;

public:
	~Rock();
	Rock();
	Rock(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};

#endif