#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
private:
	PlayerColor player;
	std::string type = "King";
	bool firstMoveDone;


public:
	~King();
	King();
	King(WCHAR* path);
	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);

};




#endif