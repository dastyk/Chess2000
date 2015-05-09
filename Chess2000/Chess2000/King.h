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

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);


};




#endif