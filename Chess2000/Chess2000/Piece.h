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
	Piece(WCHAR* path);


	PlayerColor player;
	WCHAR* type;

	Image* mImage;
public:
	
	~Piece();
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);
	Image* GetImage();
	WCHAR* GetType();


	virtual void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]) = 0;


};




#endif