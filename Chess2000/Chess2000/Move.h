#ifndef MOVE_H
#define MOVE_H

#include "Pos.h"
#include "Piece.h"
#include <string>

class Move
{
private:
	Pos startSquare;
	Pos endSquare;
	std::string movedPiece;


public:
	void recordMove(Pos start, Pos end, std::string movedPiece);


};



#endif