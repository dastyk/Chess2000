#include "Rock.h"


#pragma region Constructor and Deconstructor

Rock::Rock()
{
	type = L"Rock";
	firstMoveDone = false;
}

Rock::Rock(WCHAR* path) : Piece(path)
{
	type = L"Rock";
	firstMoveDone = false;
}

Rock::~Rock()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions

void Rock::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;
	int maximumMovesLeft, maximumMovesDown, maximumMovesUp, maximumMovesRight; //We check how far we can go in each direction (up, down, right,left)
	maximumMovesLeft = currentPos.files;
	maximumMovesRight = 8-currentPos.files-1;
	maximumMovesDown = currentPos.rank;
	maximumMovesUp = 8 - currentPos.rank - 1;

	for (int i = 1; i <= maximumMovesLeft; i++)	//For every square along the way to the left, we check
	{
		if (board[currentPos.files - i][currentPos.rank] == nullptr)	//If the square is empty
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;	//Then we add it to the movement list
		}
		else
		{
			if (board[currentPos.files - i][currentPos.rank]->GetColor() != player) //If the piece staying there is an enemy
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank;
				ReturnMoveCount++; //Then we add it to the list
			}
			maximumMovesLeft = 0; //and point out that something is blocking to the left

		}
	}
	for (int i = 1; i <= maximumMovesRight; i++) //Then we do it for the right
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

	for (int i = 1; i <= maximumMovesDown; i++) //down
	{
		if (board[currentPos.files][currentPos.rank - i] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files][currentPos.rank - i]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - i;
				ReturnMoveCount++;
			}
			maximumMovesDown = 0;

		}
	}

	for (int i = 1; i <= maximumMovesUp; i++) //and up
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