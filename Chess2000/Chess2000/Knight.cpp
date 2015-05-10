#include "Knight.h"


#pragma region Constructor and Deconstructor

Knight::Knight()
{
	type = L"Knight";
}

Knight::Knight(PlayerColor color) : Piece(color)
{
	if (player == White)
	{
		mImage = new Image(L"Resources/Pieces/White Knight.png");
	}
	else
	{
		mImage = new Image(L"Resources/Pieces/Black Knight.png");
	}
	type = L"Knight";

}

Knight::~Knight()
{
	Piece::~Piece();
}

#pragma endregion

#pragma region Get and Set functions


void Knight::GetValidMoves(Piece*** board, Pos currentPos, int &ReturnMoveCount, Pos ReturnPos[])
{
	ReturnMoveCount = 0;

	if (currentPos.files - 1 >= 0 && currentPos.rank - 2 >= 0)
	{

		if (board[currentPos.files - 1][currentPos.rank - 2] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 1][currentPos.rank - 2]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
				ReturnMoveCount++;
			}
		}
	}

	if (currentPos.files - 1 >= 0 && currentPos.rank + 2 <= 7)
	{

		if (board[currentPos.files - 1][currentPos.rank + 2] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 1][currentPos.rank + 2]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
				ReturnMoveCount++;
			}
		}
	}

	if (currentPos.files + 1 <= 7 && currentPos.rank - 2 >= 0)
	{

		if (board[currentPos.files + 1][currentPos.rank - 2] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + 1][currentPos.rank - 2]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 2;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.files + 1 <= 7 && currentPos.rank + 2 <= 7)
	{

		if (board[currentPos.files + 1][currentPos.rank + 2] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + 1][currentPos.rank + 2]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 1;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 2;
				ReturnMoveCount++;
			}
		}
	}

	if (currentPos.files - 2 >= 0 && currentPos.rank - 1 >= 0)
	{

		if (board[currentPos.files - 2][currentPos.rank - 1] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - 2;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 2][currentPos.rank - 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 2;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.files - 2 >= 0 && currentPos.rank + 1 <= 7)
	{

		if (board[currentPos.files - 2][currentPos.rank + 1] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files - 2;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files - 2][currentPos.rank + 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files - 2;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}
	}

	if (currentPos.files + 2 <= 7 && currentPos.rank - 1 >= 0)
	{

		if (board[currentPos.files + 2][currentPos.rank - 1] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + 2;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + 2][currentPos.rank - 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 2;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank - 1;
				ReturnMoveCount++;
			}
		}
	}
	if (currentPos.files + 2 <= 7 && currentPos.rank + 1 <= 7)
	{

		if (board[currentPos.files + 2][currentPos.rank + 1] == nullptr)
		{
			ReturnPos[ReturnMoveCount].files = currentPos.files + 2;
			ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
			ReturnMoveCount++;
		}
		else
		{
			if (board[currentPos.files + 2][currentPos.rank + 1]->GetColor() != player)
			{
				ReturnPos[ReturnMoveCount].files = currentPos.files + 2;
				ReturnPos[ReturnMoveCount].rank = currentPos.rank + 1;
				ReturnMoveCount++;
			}
		}
	}
}

#pragma endregion