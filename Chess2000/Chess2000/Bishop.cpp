#include "Bishop.h"


#pragma region Constructor and Deconstructor

Bishop::Bishop()
{
	type = L"Bishop";
}

Bishop::Bishop(PlayerColor color) : Piece(color)
{
	if (player == White)
	{
		mImage = new Image(L"Resources/Pieces/White Bishop.png");
	}
	else
	{
		mImage = new Image(L"Resources/Pieces/Black Bishop.png");
	}
	
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

	while (currentPos.files - maximumMovesUpLeft > 0 && currentPos.rank + maximumMovesUpLeft < 7)
	{
		maximumMovesUpLeft++;
	}

	while (currentPos.files + maximumMovesUpRight < 7 && currentPos.rank + maximumMovesUpRight < 7)
	{
		maximumMovesUpRight++;
	}


	while (currentPos.files - maximumMovesDownLeft > 0 && currentPos.rank - maximumMovesDownLeft > 0)
	{
		maximumMovesDownLeft++;
	}


	while (currentPos.files + maximumMovesDownRight < 7 && currentPos.rank - maximumMovesDownRight > 0)
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
			if (board[currentPos.files - i][currentPos.rank + i]->GetColor() != player)
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
		if (board[currentPos.files + i][currentPos.rank + i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + i][currentPos.rank + i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
				ReturnMoveCount++;
			}
			maximumMovesUpRight = 0;

		}
	}

	for (int i = 1; i <= maximumMovesDownLeft; i++)
	{
		if (board[currentPos.files - i][currentPos.rank - i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - i][currentPos.rank - i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
				ReturnMoveCount++;
			}
			maximumMovesDownLeft = 0;

		}
	}


}

#pragma endregion