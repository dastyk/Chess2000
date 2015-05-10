#include "King.h"


#pragma region Constructor and Deconstructor

King::King()
{
	type = L"King";
	firstMoveDone = false;
}

King::King(WCHAR* path) : Piece(path)
{
	type = L"King";
	firstMoveDone = false;
}

King::~King()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions


void King::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;
	if (currentPos.rank + 1 < 8)	//Check the 'upwards' movements, if we can move that way
	{
		if (currentPos.files - 1 >= 0)	//Up to the left, if we can move that way
		{
			if (board[currentPos.files - 1][currentPos.rank + 1] != nullptr)	//If there's something there
			{
				if (board[currentPos.files - 1][currentPos.rank + 1]->GetColor() != player)	//And that something is of opposite color
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files - 1;	//Then we can take it
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
			else
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;	//Otherwise we move there
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}

		if (board[currentPos.files][currentPos.rank+1] != nullptr)		//Straight up, same thing
		{
			if (board[currentPos.files][currentPos.rank]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank+1;
				ReturnMoveCount++;
			}
		}
		else
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank+1;
			ReturnMoveCount++;
		}

		if (currentPos.files + 1 < 8)	//And to the right
		{
			if (board[currentPos.files + 1][currentPos.rank + 1] != nullptr)
			{
				if (board[currentPos.files + 1][currentPos.rank + 1]->GetColor() != player)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
			else
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.rank - 1 >= 0) //The same thing for downward
	{
		if (currentPos.files - 1 > 0)
		{
			if (board[currentPos.files - 1][currentPos.rank - 1] != nullptr)
			{
				if (board[currentPos.files - 1][currentPos.rank - 1]->GetColor() != player)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
					ReturnMoveCount++;
				}
			}
			else
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}

		if (board[currentPos.files][currentPos.rank - 1] != nullptr)
		{
			if (board[currentPos.files][currentPos.rank - 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
		else
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
			ReturnMoveCount++;
		}
		if (currentPos.files + 1 < 8)
		{
			if (board[currentPos.files + 1][currentPos.rank - 1] != nullptr)
			{
				if (board[currentPos.files + 1][currentPos.rank - 1]->GetColor() != player)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
					ReturnMoveCount++;
				}
			}
			else
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.files + 1 < 8)	//To the right
	{
		if (board[currentPos.files + 1][currentPos.rank] != nullptr)
		{
			if (board[currentPos.files + 1][currentPos.rank]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank;
				ReturnMoveCount++;
			}
		}
		else
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;
		}
	}
	if (currentPos.files - 1 >= 0)	//And to the left
	{
		if (board[currentPos.files - 1][currentPos.rank] != nullptr)
		{
			if (board[currentPos.files - 1][currentPos.rank ]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank;
				ReturnMoveCount++;
			}
		}
		else
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;
		}
	}

}

#pragma endregion