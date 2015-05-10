#include "Pawn.h"


#pragma region Constructor and Deconstructor

Pawn::Pawn()
{
	type = L"Pawn";
	firstMoveDone = false;
}

Pawn::Pawn(WCHAR* path) : Piece(path)
{
	type = L"Pawn";
	firstMoveDone = false;
}


Pawn::~Pawn()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions


void Pawn::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;
	if (player == White)	//Check if we're white or black, since we can only move in one direction (such rasism)
	{
		if (!firstMoveDone)	//If we haven't moved, we have the choice to move two steps forwad
		{
			if (board[currentPos.files][currentPos.rank + 1] == nullptr)	//That is, if no one is in the way.
			{
				if (board[currentPos.files][currentPos.rank + 2] == nullptr)	//On either of those squares.
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files;	//These things save the move to the check that's aboard. If we can move, we go in here and save it
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
					ReturnMoveCount++;	//We also add one to the number of moves we can make.
				}
			}
		}
		if (currentPos.rank + 1 < 8)	//Check so we haven't reached the end (top) of the board
		{
			if (board[currentPos.files][currentPos.rank + 1] == nullptr)	//Then we are allowed to move upwards
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}

		if (currentPos.files + 1 < 8 && currentPos.rank + 1 < 8)	//Check so that we can move diagonally up right
		{
			if (board[currentPos.files + 1][currentPos.rank + 1] != nullptr)	//but only if there is a piece there!
			{
				if (board[currentPos.files + 1][currentPos.rank + 1]->GetColor() == Black)	//and that piece is black!
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
		}
		if (currentPos.files - 1 >= 0 && currentPos.rank + 1 < 8)	//Same to up left
		{
			if (board[currentPos.files - 1][currentPos.rank + 1] != nullptr) 
			{
				if (board[currentPos.files - 1][currentPos.rank + 1]->GetColor() == Black)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
		}
	}
	else
	{
		if (!firstMoveDone) //If we haven't moved, we have the choice to move two steps forwad
		{
			if (board[currentPos.files][currentPos.rank - 1] == nullptr) //That is, if no one is in the way.
			{
				if (board[currentPos.files][currentPos.rank - 2] == nullptr) //On either of the squares
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
					ReturnMoveCount++;
				}
			}
		}
		if (currentPos.rank - 1 >= 0) //Check so we haven't reached the end of the board
		{
			if (board[currentPos.files][currentPos.rank - 1] == nullptr) //And that no one is before us!
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
		if (currentPos.files + 1 < 8 && currentPos.rank - 1 >= 0) //Check if we can move diagonally down right.
		{
			if (board[currentPos.files + 1][currentPos.rank - 1] != nullptr) //That is, if there's someone there
			{
				if (board[currentPos.files + 1][currentPos.rank - 1]->GetColor() == White) //And that someone is an enemy
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
					ReturnMoveCount++;
				}
			}
		}
		if (currentPos.files - 1 >= 0 && currentPos.rank - 1 >= 0) //Or down left
		{
			if (board[currentPos.files - 1][currentPos.rank - 1] != nullptr) //That is, if there's someone there
			{
				if (board[currentPos.files - 1][currentPos.rank - 1]->GetColor() == White) //And that someone is an enemy
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
					ReturnMoveCount++;
				}
			}
		}
	}


}

#pragma endregion