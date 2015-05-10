#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Enum.h"
#include "Pos.h"
#include "GraphicsClass.h"

class Piece
{
protected:
	//Constructor
	Piece();
	Piece(PlayerColor color);


	PlayerColor player;
	WCHAR* type;
	bool firstMoveDone;

	Image* mImage;
public:
	
	~Piece();
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);
	Image* GetImage();
	WCHAR* GetType();
	void HasMoved();


	virtual void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]) = 0;


};




#endif