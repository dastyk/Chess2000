#include "Bishop.h"


#pragma region Constructor and Deconstructor

Bishop::Bishop()
{
	type = L"Bishop";
}

Bishop::Bishop(WCHAR* path) : Piece(path)
{
	type = L"Bishop";
}

Bishop::~Bishop()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions


void Bishop::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;
	int maximumMovesUpLeft, maximumMovesUpRight, maximumMovesDownLeft, maximumMovesDownRight;
	maximumMovesUpLeft = 0;
	maximumMovesUpRight = 0;
	maximumMovesDownLeft = 0;
	maximumMovesDownRight = 0;


	while (currentPos.rank + maximumMovesUpLeft < 7 && currentPos.files - maximumMovesUpLeft > 0)
	{
		maximumMovesUpLeft++;
	}

	while (currentPos.rank + maximumMovesUpRight < 7 && currentPos.files + maximumMovesUpRight < 7)
	{
		maximumMovesUpRight++;
	}


	while (currentPos.rank - maximumMovesDownLeft > 0 && currentPos.files - maximumMovesDownLeft > 0)
	{
		maximumMovesDownLeft++;
	}


	while (currentPos.rank - maximumMovesDownRight > 0 && currentPos.files + maximumMovesUpLeft < 7)
	{
		maximumMovesDownRight++;
	}




	for (int i = 1; i <= maximumMovesUpLeft; i++)
	{
		if (board[currentPos.files - i][currentPos.rank + i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 1][currentPos.rank + i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
				ReturnMoveCount++;
			}
			maximumMovesUpLeft = 0;

		}
	}
	for (int i = 1; i <= maximumMovesDownRight; i++)
	{
		if (board[currentPos.files + i][currentPos.rank - i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + i][currentPos.rank - i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
				ReturnMoveCount++;
			}
			maximumMovesDownRight = 0;

		}
	}

	for (int i = 1; i <= maximumMovesUpRight; i++)
	{
		if (board[currentPos.files + i][currentPos.rank - i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + i][currentPos.rank - i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
				ReturnMoveCount++;
			}
			maximumMovesUpRight = 0;

		}
	}

	for (int i = 1; i <= maximumMovesDownLeft; i++)
	{
		if (board[currentPos.files - i][currentPos.rank + i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files][currentPos.rank + i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
				ReturnMoveCount++;
			}
			maximumMovesDownLeft = 0;

		}
	}



}

#pragma endregion