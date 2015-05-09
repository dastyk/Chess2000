#include "Rock.h"


#pragma region Constructor and Deconstructor

Rock::Rock()
{
	type = "Rock";
	firstMoveDone = false;
}

Rock::~Rock()
{

}

#pragma endregion

#pragma region Get and Set functions

void Rock::SetColor(PlayerColor playerColor)
{
	player = playerColor;
}

PlayerColor Rock::GetColor()
{
	return player;
}

void Rock::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;
	int maximumMovesLeft, maximumMovesDown, maximumMovesUp, maximumMovesRight;
	maximumMovesLeft = currentPos.files;
	maximumMovesRight = 8-currentPos.files-1;
	maximumMovesDown = currentPos.rank;
	maximumMovesUp = 8 - currentPos.rank - 1;

	for (int i = 1; i <= maximumMovesLeft; i++)
	{
		if (board[currentPos.files - i][currentPos.rank] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 1][currentPos.rank]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank;
				ReturnMoveCount++;
			}
			maximumMovesLeft = 0;

		}
	}
	for (int i = 1; i <= maximumMovesRight; i++)
	{
		if (board[currentPos.files + i][currentPos.rank] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + i][currentPos.rank]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank;
				ReturnMoveCount++;
			}
			maximumMovesRight = 0;

		}
	}

	for (int i = 1; i <= maximumMovesDown; i++)
	{
		if (board[currentPos.files][currentPos.rank-i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank-i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files][currentPos.rank-i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank-i;
				ReturnMoveCount++;
			}
			maximumMovesDown = 0;

		}
	}

	for (int i = 1; i <= maximumMovesUp; i++)
	{
		if (board[currentPos.files][currentPos.rank + i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files][currentPos.rank + i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
				ReturnMoveCount++;
			}
			maximumMovesUp = 0;

		}
	}



}

#pragma endregion