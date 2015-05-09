#include "PlayState.h"
#include "PlayGame.h"

PlayState::PlayState()
{
	validMoveCount = 0;

	mMenuItems.push_back(new TextLabel(150, 5, 550, 50, L"CHESS 2000 FUCK YEAHH!!!!", 30, Color(255, 255, 0, 0)));

	board = new Piece**[RANKS];
	for (UINT x = 0; x < RANKS; x++)
	{
		board[x] = new Piece*[FILES];
		for (UINT y = 0; y < FILES; y++)
		{
			UINT c = (x+y) % 2;
			board[x][y] = nullptr;
			mMenuItems.push_back(squares[x][y] = new TextLabel(200 + x * 50, 50 + (FILES - y) * 50, 50, 50, L"", 45, Color(255, c * 255, c * 255, c * 255)));
		}
	}

	for (int i = 0; i < RANKS; i++)
	{
		board[i][1] = new Pawn(L"Resources/Pieces/White Pawn.png");
		board[i][1]->SetColor(White);
		board[i][6] = new Pawn(L"Resources/Pieces/Black Pawn.png");
		board[i][6]->SetColor(Black);
	}

	board[0][0] = new Rock(L"Resources/Pieces/White Rock.png");
	board[1][0] = new Knight(L"Resources/Pieces/White Knight.png");
	board[2][0] = new Bishop(L"Resources/Pieces/White Bishop.png");
	board[3][0] = new Queen(L"Resources/Pieces/White Queen.png");
	board[4][0] = new King(L"Resources/Pieces/White King.png");
	board[5][0] = new Bishop(L"Resources/Pieces/White Bishop.png");
	board[6][0] = new Knight(L"Resources/Pieces/White Knight.png");
	board[7][0] = new Rock(L"Resources/Pieces/White Rock.png");

	board[0][7] = new Rock(L"Resources/Pieces/Black Rock.png");
	board[1][7] = new Knight(L"Resources/Pieces/Black Knight.png");
	board[2][7] = new Bishop(L"Resources/Pieces/Black Bishop.png");
	board[3][7] = new Queen(L"Resources/Pieces/Black Queen.png");
	board[4][7] = new King(L"Resources/Pieces/Black King.png");
	board[5][7] = new Bishop(L"Resources/Pieces/Black Bishop.png");
	board[6][7] = new Knight(L"Resources/Pieces/Black Knight.png");
	board[7][7] = new Rock(L"Resources/Pieces/Black Rock.png");


	for (int i = 0; i < RANKS; i++)
	{
		board[i][0]->SetColor(White);
		board[i][7]->SetColor(Black);
	}

}


PlayState::~PlayState()
{
	GameState::~GameState();

	 
	for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{
			if (board[x][y])
			{
				delete board[x][y];
				board[x][y] = nullptr;
			}
		}
		delete[] board[x];
	}
	delete[] board;
}

bool PlayState::Update(float dt)
{
	GameState::Update(dt);


	return true;
}


bool PlayState::Render()
{
	GameState::Render();
	GraphicsClass& g = GraphicsClass::GetInstance();


	for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{
			if (board[x][y])
			{
				g.DrawImage(board[x][y]->GetImage(), 200 + x * 50, 50 + (FILES - y) * 50, 50, 50);
			}
		}
	}

	for (int i = 0; i < validMoveCount; i++)
	{
		g.DrawRectangle(Color(255, 255, 0, 0), 3, 200 + validMoves[i].rank * 50, 50 + (FILES - validMoves[i].files) * 50, 50, 50);
	}
	return true;
}


bool PlayState::HandleInput()
{
	InputClass& i = InputClass::GetInstance();

	// Check to see if user has pressed the escape button
	if (i.IsKeyDown(VK_ESCAPE))
	{
		PlayGame::GetInstance().ChangeState(PAUSESTATE); // If key was pressed change to pause state.		
	}

	for (UINT x = 0; x < RANKS; x++)
	{
		for (UINT y = 0; y < FILES; y++)
		{
			if (board[x][y])
			{
				if (squares[x][y]->IsClicked())
				{
					validMoveCount = 0;
					board[x][y]->GetValidMoves(board, Pos(x, y), validMoveCount, validMoves);
					/*delete board[x][y];
					board[x][y] = nullptr;*/
					//lastPick = Pos(x, y);
				}
			}
		}
	}

	return true;
}