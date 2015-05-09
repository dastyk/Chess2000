#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
private:

	bool firstMoveDone;


public:
	~King();
	King();
	King(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};




#endif