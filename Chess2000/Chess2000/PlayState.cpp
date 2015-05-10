#include "PlayState.h"
#include "PlayGame.h"

PlayState::PlayState()
{
	mPawnAtEnd = Pos();

	// Set who starts the game.
	currPlayer = White;

	// Deselect all pieces.
	validMoveCount = 0;
	lastPick = Pos();

	// Create UI elements
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png", -1));
	mMenuItems.push_back(new TextLabel(145, 5, 550, 50, L"CHESS 2000 FUCK YEAHH!!!!", 30, Color(0, 255, 0, 0), -1));
	mMenuItems.push_back(new TextLabel(160, 50, 170, 25, L"Press 'Escape' to Pause.", 10, Color(255, 100, 100, 200), -1));

	mMenuItems.push_back(lastMoveList = new TextListClass(620, 100, 200, 350, L"Previous Moves:", 15, Color(255, 100, 100, 200), 1));

	WCHAR** letters = new WCHAR*[8];
	letters[0] = L"A";
	letters[1] = L"B";
	letters[2] = L"C";
	letters[3] = L"D";

	letters[4] = L"E";
	letters[5] = L"F";
	letters[6] = L"G";
	letters[7] = L"H";

	for (UINT x = 0; x < FILES; x++)
	{
		mMenuItems.push_back(new TextLabel(200 + 50 * x, 500, 30, 30, letters[x], 10, Color(255, 100, 100, 200), -1));
	}

	letters[0] = L"1";
	letters[1] = L"2";
	letters[2] = L"3";
	letters[3] = L"4";

	letters[4] = L"5";
	letters[5] = L"6";
	letters[6] = L"7";
	letters[7] = L"8";



	for (UINT x = 0; x < RANKS; x++)
	{
		mMenuItems.push_back(new TextLabel(170, 470 - 50 * x, 30, 30, letters[x], 10, Color(255, 100, 100, 200), -1));
	}

	delete[] letters;

	board = new Piece**[FILES];
	for (UINT x = 0; x < FILES; x++)
	{
		board[x] = new Piece*[RANKS];
		for (UINT y = 0; y < RANKS; y++)
		{
			UINT c = (x + y) % 2;
			board[x][y] = nullptr;
			mMenuItems.push_back(squares[x][y] = new TextLabel(200 + x * 50, 50 + (FILES - y) * 50, 50, 50, L"", 45, Color(255, c * 255, c * 255, c * 255), 1,IDC_HAND,true, Color(100,255,0,0)));
		}
	}

	mMenuItems.push_back(mPawnAtEndPop = new PopUpClass(250, 150, 300, 300, L"Pick a piece.", 15, Color(255, 100, 100, 200), 10));
	mPawnAtEndPop->AddItem(new Button(75, 75, 125, 30, L"Queen", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 110, 125, 30, L"Rock", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 145, 125, 30, L"Knight", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 180, 125, 30, L"Bishop", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);

	// Create all the game pieces.
	for (int i = 0; i < FILES; i++)
	{
		board[i][1] = new Pawn(White);
		board[i][6] = new Pawn(Black);
	}

	board[0][0] = new Rock(White);
	board[1][0] = new Knight(White);
	board[2][0] = new Bishop(White);
	board[3][0] = new Queen(White);
	board[4][0] = new King(White);
	board[5][0] = new Bishop(White);
	board[6][0] = new Knight(White);
	board[7][0] = new Rock(White);

	board[0][7] = new Rock(Black);
	board[1][7] = new Knight(Black);
	board[2][7] = new Bishop(Black);
	board[3][7] = new Queen(Black);
	board[4][7] = new King(Black);
	board[5][7] = new Bishop(Black);
	board[6][7] = new Knight(Black);
	board[7][7] = new Rock(Black);

}


PlayState::~PlayState()
{
	GameState::~GameState();

	// Delete the board, and remaining pieces.
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

	// Delete all made moves.
	UINT count = lastMoves.size();
	for (UINT x = 0; x < count; x++)
	{
		delete lastMoves[x];
		lastMoves[x] = nullptr;

	}
}

bool PlayState::Update(float dt)
{
	GameState::Update(dt);

	return true;
}


bool PlayState::Render()
{



	GameState::Render(); // All squares and menuitems are rendered in here.
	GraphicsClass& g = GraphicsClass::GetInstance();

	if (!mPawnAtEndPop->IsPop())
	{

	// Loop through all the squares.
	for (UINT x = 0; x < FILES; x++)
	{
		for (UINT y = 0; y < RANKS; y++)
		{
			if (board[x][y])
			{
				// if there is a piece there, draw it.
				g.DrawImage(board[x][y]->GetImage(), 200 + x * 50, 50 + (RANKS - y) * 50, 50, 50);
			}
		}
	}

	// Loop through all validMoves, and draw them.
	for (int i = 0; i < validMoveCount; i++)
	{
		g.DrawRectangle(Color(255, 255, 0, 0), 3, 200 + validMoves[i].files * 50, 50 + (RANKS - validMoves[i].rank) * 50, 50, 50);
	}
	}
	return true;
}


bool PlayState::HandleInput()
{
	if (mPawnAtEndPop->IsPop())
	{
		int answer = -1;
		mPawnAtEndPop->PopUp(answer);
		if (answer >= 0)
		{
			PlayerColor c = board[mPawnAtEnd.files][mPawnAtEnd.rank]->GetColor();
			switch (answer)
			{
			case 0:
			{
				delete board[mPawnAtEnd.files][mPawnAtEnd.rank];
				board[mPawnAtEnd.files][mPawnAtEnd.rank] = new Queen(c);
				break;
			}
			case 1:
			{
				delete board[mPawnAtEnd.files][mPawnAtEnd.rank];
				board[mPawnAtEnd.files][mPawnAtEnd.rank] = new Rock(c);
				break;
			}
			case 2:
			{
				delete board[mPawnAtEnd.files][mPawnAtEnd.rank];
				board[mPawnAtEnd.files][mPawnAtEnd.rank] = new Knight(c);
				break;
			}
			case 3:
			{
				delete board[mPawnAtEnd.files][mPawnAtEnd.rank];
				board[mPawnAtEnd.files][mPawnAtEnd.rank] = new Bishop(c);
				break;
			}
			}
			
		}
	}
	else
	{
	InputClass& i = InputClass::GetInstance();

	// Check to see if user has pressed the escape button
	if (i.IsKeyDown(VK_ESCAPE))
	{
		PlayGame::GetInstance().ChangeState(PAUSESTATE); // If key was pressed change to pause state.		
	}

	// If a piece is selected, loop thourgh the valid moves.
	if (validMoveCount > 0)
	{
		for (int x = 0; x < validMoveCount; x++)
		{
			// check if a valid move has been selected.
			if (squares[validMoves[x].files][validMoves[x].rank]->IsClicked())
			{
				// If there is currently a piece in this pos, remove it.
				if (board[validMoves[x].files][validMoves[x].rank])
				{
					if (board[validMoves[x].files][validMoves[x].rank]->GetType() == L"King")
					{
						PlayGame::GetInstance().EndGameKingTaken(currPlayer);						
					}
					delete board[validMoves[x].files][validMoves[x].rank];				
				}

					if (board[lastPick.files][lastPick.rank]->GetType() == L"Pawn")
					{

						if (validMoves[x].rank == ((1 - board[lastPick.files][lastPick.rank]->GetColor()) * 7))
						{
							int ret = -1;
							mPawnAtEnd = validMoves[x];
							mPawnAtEndPop->PopUp(ret);
						}
						
						

					}

				// Record this move to lastMoves
				lastMoves.push_back(new Move(lastPick, validMoves[x], board[lastPick.files][lastPick.rank]->GetType(), lastMoves.size() + 1));
				
				// Add the move to the Textlist
					lastMoveList->AddItem(lastMoves[lastMoves.size() - 1]->GetMoveText());

				//Set that the piece has been moved
				board[lastPick.files][lastPick.rank]->HasMoved();

				// Move the piece
				board[validMoves[x].files][validMoves[x].rank] = board[lastPick.files][lastPick.rank];
				board[lastPick.files][lastPick.rank] = nullptr;

				// Deselect the piece
				validMoveCount = 0;
				lastPick = Pos();

				// Change who's turn it is.
				currPlayer = (currPlayer == White) ? Black : White;


			}
		}
	}


	// Loops through all squares and check if there is a piece there.
	for (UINT x = 0; x < FILES; x++)
	{
		for (UINT y = 0; y < RANKS; y++)
		{
			if (board[x][y])
			{
				// Check if this piece belongs to the current player.
				if (board[x][y]->GetColor() == currPlayer)
				{
					// If there is a piece on the square, check if the player clicked it.
					if (squares[x][y]->IsClicked())
					{
						// If player clicked the piece, check if it was already selected.
						validMoveCount = 0;
						if (lastPick == Pos(x, y))
						{
							// If piece was selected, unselect it.
							lastPick = Pos();
						}
						else
						{
							// else select the piece and get all valid moves for the piece.
							lastPick = Pos(x, y);
							board[x][y]->GetValidMoves(board, lastPick, validMoveCount, validMoves);

						}
					}
				}
			}
		}
	}
	}
	return true;
}