#include "Piece.h"

Piece::Piece()
{
	mImage = nullptr;
}
Piece::Piece(PlayerColor color) : player(color)
{
	player = color;
}

Piece::~Piece()
{
	if (mImage)		
	{
		delete mImage;
		mImage = 0;
	}
}

void Piece::SetColor(PlayerColor playerColor)
{
	player = playerColor;
}

PlayerColor Piece::GetColor()
{
	return player;
}

Image* Piece::GetImage()
{
	return mImage;
}

WCHAR* Piece::GetType()
{
	return type;
}

void Piece::HasMoved()
{
	firstMoveDone = true;
}