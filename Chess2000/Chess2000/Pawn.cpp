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
	if (player == White)
	{
		if (!firstMoveDone)
		{
			if (board[currentPos.files][currentPos.rank + 2] == nullptr)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
				ReturnMoveCount++;
			}
			
		}
		if (currentPos.rank + 1 < 8)
		{
			if (board[currentPos.files][currentPos.rank + 1] == nullptr)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}

		if (currentPos.files + 1 < 8 && currentPos.rank + 1 < 8)
		{
			if (board[currentPos.files + 1][currentPos.rank + 1] != nullptr)
			{
				if (board[currentPos.files + 1][currentPos.rank + 1]->GetColor() == Black)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
		}
		if (currentPos.files - 1 >= 0 && currentPos.rank + 1 < 8)
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
		if (!firstMoveDone)
		{
			if (board[currentPos.files][currentPos.rank - 2] == nullptr)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
				ReturnMoveCount++;
			}

		}
		if (currentPos.rank - 1 >= 0)
		{
			if (board[currentPos.files][currentPos.rank - 1] == nullptr)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
		if (currentPos.files + 1 < 8 && currentPos.rank - 1 >= 0)
		{
			if (board[currentPos.files + 1][currentPos.rank - 1] != nullptr)
			{
				if (board[currentPos.files + 1][currentPos.rank - 1]->GetColor() == White)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
					ReturnMoveCount++;
				}
			}
		}
		if (currentPos.files - 1 >= 0 && currentPos.rank - 1 >= 0)
		{
			if (board[currentPos.files - 1][currentPos.rank - 1] != nullptr)
			{
				if (board[currentPos.files - 1][currentPos.rank - 1]->GetColor() == White)
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