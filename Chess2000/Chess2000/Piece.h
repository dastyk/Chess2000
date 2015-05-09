#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Enum.h"
#include "Pos.h"
#include "GraphicsClass.h"

class Piece
{
private:
	PlayerColor player;
	std::string type;

	Image* mImage;

protected:
	//Constructor
	Piece();
	Piece(WCHAR* path);

public:
	
	~Piece();
	PlayerColor GetColor();
	void SetColor(PlayerColor playerColor);
	Image* GetImage();

	virtual void GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[]) = 0;


};




#endif