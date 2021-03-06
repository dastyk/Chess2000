#include "Queen.h"


#pragma region Constructor and Deconstructor

Queen::Queen()
{
	type = L"Queen";
}

Queen::Queen(PlayerColor color) : Piece(color)
{
	if (player == White)
	{
		mImage = new Image(L"Resources/Pieces/White Queen.png");
	}
	else
	{
		mImage = new Image(L"Resources/Pieces/Black Queen.png");
	}
	type = L"Queen";
}

Queen::~Queen()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions



void Queen::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	//Queen is a combination of Rock and Bishop, read their comments.
	ReturnMoveCount = 0;
	int maximumMovesUpLeft, maximumMovesUpRight, maximumMovesDownLeft, maximumMovesDownRight;
	int maximumMovesLeft, maximumMovesDown, maximumMovesUp, maximumMovesRight;
	maximumMovesLeft = currentPos.files;
	maximumMovesRight = 8 - currentPos.files-1;
	maximumMovesDown = currentPos.rank;
	maximumMovesUp = 8 - currentPos.rank-1;
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
	

	for (int i = 1; i <= maximumMovesLeft; i++)
	{
		if (board[currentPos.files-i][currentPos.rank] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - i;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - i][currentPos.rank]->GetColor() != player)
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