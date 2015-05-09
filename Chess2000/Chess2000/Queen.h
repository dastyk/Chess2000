#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
private:
	Color player;
	std::string type = "Queen";

public:
	~Queen();
	Queen();

	void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]);
	Color GetColor();
	void SetColor(Color playerColor);


};

#endif