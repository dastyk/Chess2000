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
	int maximumMovesUpLeft, maximumMovesUpRight, maximumMovesDownLeft, maximumMovesDownRight; //Need to check how far we can move
	maximumMovesUpLeft = 0;
	maximumMovesUpRight = 0;
	maximumMovesDownLeft = 0;
	maximumMovesDownRight = 0;

	while (currentPos.files - maximumMovesUpLeft > 0 && currentPos.rank + maximumMovesUpLeft < 7) //Diagonally UpLeft
	{
		maximumMovesUpLeft++;
	}

	while (currentPos.files + maximumMovesUpRight < 7 && currentPos.rank + maximumMovesUpRight < 7) //Diagonally UpRight
	{
		maximumMovesUpRight++;
	}


	while (currentPos.files - maximumMovesDownLeft > 0 && currentPos.rank - maximumMovesDownLeft > 0) //Diagonally DownLeft
	{
		maximumMovesDownLeft++;
	}


	while (currentPos.files + maximumMovesDownRight < 7 && currentPos.rank - maximumMovesDownRight > 0) //Diagonally DownRight
	{
		maximumMovesDownRight++;
	}

	for (int i = 1; i <= maximumMovesUpLeft; i++)	//We can move UpLeft
	{
		if (board[currentPos.files - i][currentPos.rank + i] == nullptr)	//For as long as nothing is in the way
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - i][currentPos.rank + i]->GetColor() != player)	//Or if that something is of the opposite color
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - i;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + i;
				ReturnMoveCount++;
			}
			maximumMovesUpLeft = 0;		//When we reach a 'something' blocking the way, we have reached the end of the line, and can't move further

		}
	}
	for (int i = 1; i <= maximumMovesDownRight; i++)	//The same is done for DownRight
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

	for (int i = 1; i <= maximumMovesUpRight; i++)		//UpRight
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

	for (int i = 1; i <= maximumMovesDownLeft; i++)		//DownLeft
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