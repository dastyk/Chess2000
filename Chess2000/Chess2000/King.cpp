#include "King.h"


#pragma region Constructor and Deconstructor

King::King()
{
	type = "King";
	firstMoveDone = false;
}

King::King(WCHAR* path) : Piece(path)
{
	type = "King";
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
	if (currentPos.rank + 1 < 8)
	{
		if (currentPos.files - 1 > 0)
		{
			if (board[currentPos.files - 1][currentPos.rank + 1] != nullptr)
			{
				if (board[currentPos.files - 1][currentPos.rank + 1]->GetColor() != player)
				{
					ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
					ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
					ReturnMoveCount++;
				}
			}
			else
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}

		if (board[currentPos.files][currentPos.rank + 1] != nullptr)
		{
			if (board[currentPos.files][currentPos.rank + 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}
		else
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
			ReturnMoveCount++;
		}
		if (currentPos.files + 1 > 0)
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
	if (currentPos.rank - 1 > 8)
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
		if (currentPos.files + 1 > 0)
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
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.files + 1 > 0)
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
	if (currentPos.files - 1 < 0)
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