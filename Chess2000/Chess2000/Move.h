#ifndef MOVE_H
#define MOVE_H

#include "Pos.h"
#include "Piece.h"
#include <sstream>


class Move
{
private:
	Pos startSquare;
	Pos endSquare;
	wchar_t* movedPiece;
	wchar_t* moveText;

public:
	wchar_t* GetMoveText();

	Move();
	Move(Pos start, Pos end, wchar_t* movedPiece, UINT order);
	~Move();

};



#endif