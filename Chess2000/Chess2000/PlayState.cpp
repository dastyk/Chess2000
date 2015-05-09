#include "PlayState.h"
#include "PlayGame.h"

PlayState::PlayState()
{
	for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{
			UINT c = (x+y) % 2;
			board[x][y] = nullptr;
			mMenuItems.push_back(new TextLabel(200 + x * 50, 50 + (FILES - y) * 50, 50, 50, L"", 45, Color(255, c * 255, c * 255, c * 255)));
		}
	}

	//for (int i = 0; i < RANKS; i++)
	//{
	//	board[i][2] = new Pawn;
	//	board[i][2]->SetColor(White);
	//	board[i][6] = new Pawn;
	//	board[i][6]->SetColor(Black);
	//}

	board[0][0] = new Rock();
	//board[1][0] = new Knight;
	//board[2][0] = new Bishop;
	//board[3][0] = new Queen;
	//board[4][0] = new King;
	//board[5][0] = new Bishop;
	//board[6][0] = new Knight;
	//board[7][0] = new Rock;
	//board[0][7] = new Rock;
	//board[1][7] = new Knight;
	//board[2][7] = new Bishop;
	//board[3][7] = new Queen;
	//board[4][7] = new King;
	//board[5][7] = new Bishop;
	//board[6][7] = new Knight;
	//board[7][7] = new Rock;


	//for (int i = 0; i < RANKS; i++)
	//{
	//	board[i][0]->SetColor(White);
	//	board[i][7]->SetColor(Black);
	//}

}


PlayState::~PlayState()
{
	//GameState::~GameState();
	delete board[0][0];
	board[0][0] = 0;
	/*for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{
			if (board[x][y])
			{
				delete board[x][y];
				board[x][y] = nullptr;
			}
		}
	}*/

}

bool PlayState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool PlayState::Render()
{
	GameState::Render();


	for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{


			if (board[x][y])
			{
				
			}
		}
	}


	return true;
}


bool PlayState::HandleInput()
{
	InputClass& i = InputClass::GetInstance();

	// Check to see if user has pressed the escape button
	if (i.IsKeyDown(VK_ESCAPE))
	{
		//PlayGame::GetInstance().ChangeState(PAUSESTATE); // If key was pressed change to pause state.
		PlayGame::GetInstance().EndGame();
	}

	return true;
}