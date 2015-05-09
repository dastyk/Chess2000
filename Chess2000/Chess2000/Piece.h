#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Enum.h"
#include "Pos.h"

class Piece
{
private:
	PlayerColor player;
	std::string type;

protected:
	//Constructor
	Piece();


public:
	
	~Piece();
	virtual PlayerColor GetColor() = 0;
	virtual void SetColor(PlayerColor playerColor) = 0;
	virtual void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]) = 0;
};




#endif