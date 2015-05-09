#include "PlayState.h"


PlayState::PlayState()
{
	for (int i = 0; i < 8; i++)
	{
		board[i][2] = new Pawn;
		board[i][2]->SetColor(White);
		board[i][6] = new Pawn;
		board[i][6]->SetColor(Black);
	}

	board[0][1] = new Rock;
	board[1][1] = new Knight;
	board[2][1] = new Bishop;
	board[3][1] = new Queen;
	board[4][1] = new King;
	board[5][1] = new Bishop;
	board[6][1] = new Knight;
	board[7][1] = new Rock;
	board[0][7] = new Rock;
	board[1][7] = new Knight;
	board[2][7] = new Bishop;
	board[3][7] = new Queen;
	board[4][7] = new King;
	board[5][7] = new Bishop;
	board[6][7] = new Knight;
	board[7][7] = new Rock;


	for (int i = 0; i < 8; i++)
	{
		board[i][1]->SetColor(White);
		board[i][7]->SetColor(Black);
	}

}


PlayState::~PlayState()
{
}

bool PlayState::Update(float dt)
{
	return true;
}


bool PlayState::Render()
{
	return true;
}


bool PlayState::HandleInput()
{
	return true;
}