#include "PlayState.h"
#include "PlayGame.h"

PlayState::PlayState()
{
	mPawnAtEnd = Pos();

	// Set who starts the game.
	currPlayer = White;

	// Deselect all pieces.
	Deselect();



//-------------------------------------------------------------////

//					Create UI elements
//-------------------------------------------------------------////
	mMenuItems.push_back(new ImageClass(0, 0, 800, 600, Color(0, 0, 0, 0), L"Resources/chessBG.png", -1));
	mMenuItems.push_back(new TextLabel(145, 5, 550, 50, L"CHESS 2000 FUCK YEAHH!!!!", 30, Color(0, 255, 0, 0), -1));
	mMenuItems.push_back(new TextLabel(800 - 170, 600 - 25, 170, 25, L"Press 'Escape' to Pause.", 10, Color(200, 100, 100, 200), -1));
	mMenuItems.push_back(mPauseButton = new Button(620, 460, 200, 30, L"Pause Game", 15, Color(200, 100, 100, 200), 1));
	mMenuItems.push_back(mSurrenderButton = new Button(620, 510, 200, 30, L"Surrender Game", 15, Color(200, 100, 100, 200), 1));

	mMenuItems.push_back(lastMoveList = new TextListClass(620, 100, 200, 350, L"Previous Moves:", 15, Color(200, 100, 100, 200), 1));


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
		mMenuItems.push_back(new TextLabel(200 + 50 * x, 500, 30, 30, letters[x], 10, Color(200, 100, 100, 200), -1));
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
		mMenuItems.push_back(new TextLabel(170, 470 - 50 * x, 30, 30, letters[x], 10, Color(200, 100, 100, 200), -1));
	}

	delete[] letters;

	// Squares for the board
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

	// PawnAtEnd PopUp setup
	mMenuItems.push_back(mPawnAtEndPop = new PopUpClass(250, 150, 300, 300, L"Pick a piece.", 15, Color(255, 100, 100, 200), 10));
	mPawnAtEndPop->AddItem(new Button(75, 75, 125, 30, L"Queen", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 110, 125, 30, L"Rock", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 145, 125, 30, L"Knight", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);
	mPawnAtEndPop->AddItem(new Button(75, 180, 125, 30, L"Bishop", 15, Color(255, 255, 255, 255), 1), POPUPBUTTON);


//-------------------------------------------------------------////

//				Create all the game pieces.
//-------------------------------------------------------------////

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

	if (!mPawnAtEndPop->IsPop()) // Dont render the pices if popup is open. (They overlap the popup).
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
//-------------------------------------------------------------////

//			Check to see if a pawn is at the end
//-------------------------------------------------------------////
	if (mPawnAtEndPop->IsPop())
	{
		// If there is, wait for answer from player.
		WaitForPopAnswer();
		return true;
	}

//--------------------------------------------------------/////


	// If pawn not at end, continue as usual.
	InputClass& i = InputClass::GetInstance();

//				Button and key presses
//-------------------------------------------------------------////

	// Check to see if user has pressed the escape button
	if (i.IsKeyDown(VK_ESCAPE))
	{
		PlayGame::GetInstance().ChangeState(PAUSESTATE); // If key was pressed change to pause state.		
	}

	// Check if pause button is clicked.
	if (mPauseButton->IsClicked())
		PlayGame::GetInstance().ChangeState(PAUSESTATE); // If button was pressed change to pause state.		

	// Check if surrender button is clicked.
	if (mSurrenderButton->IsClicked())
	{
		// If button was pressed, decide winner and end game.	
		PlayGame::GetInstance().EndGameKingTaken((currPlayer == White) ? Black : White);
		return true;
	}

//-------------------------------------------------------------////

//						Pick a move
//-------------------------------------------------------------////
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
					// If the pieces moved to the king pos, decide winner and end game.
					if (board[validMoves[x].files][validMoves[x].rank]->GetType() == L"King")
					{
						PlayGame::GetInstance().EndGameKingTaken(currPlayer);
						return true;
					}
					delete board[validMoves[x].files][validMoves[x].rank];
				}

				// If the moved piece is a pawn
				PieceIsPawn(validMoves[x]);

				// Record this move.
				RecordMove(validMoves[x]);
				
				//Set that the piece has been moved
				board[lastPick.files][lastPick.rank]->HasMoved();

				// Move the piece
				board[validMoves[x].files][validMoves[x].rank] = board[lastPick.files][lastPick.rank];
				board[lastPick.files][lastPick.rank] = nullptr;

				// Deselect the piece
				Deselect();

				// Change who's turn it is.
				currPlayer = (currPlayer == White) ? Black : White;

				return true;
			}
		}
	}

//-------------------------------------------------------------////

//						Pick a piece
//-------------------------------------------------------------////

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
						if (lastPick == Pos(x, y))
						{
							// If piece was selected, deselect it.
							Deselect();
							return true;
						}
						else
						{
							// else select the piece and get all valid moves for the piece.
							lastPick = Pos(x, y);
							validMoveCount = 0;
							board[x][y]->GetValidMoves(board, lastPick, validMoveCount, validMoves);
							return true;
						}
					}
				}
			}
		}
	}

	return true;
}

void PlayState::WaitForPopAnswer()
{
	int answer = -1;
	mPawnAtEndPop->PopUp(answer);
	if (answer >= 0)
	{
		// Create the selected piece.
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


void PlayState::PieceIsPawn(Pos e)
{
	// Check if lastPick is a pawn.
	if (board[lastPick.files][lastPick.rank]->GetType() == L"Pawn")
	{
		// Check if it moves to the end of the board
		if (e.rank == ((1 - board[lastPick.files][lastPick.rank]->GetColor()) * 7))
		{
			// If it is at the end, open pawn at end popup.
			int ret = -1;
			mPawnAtEnd = e;
			mPawnAtEndPop->PopUp(ret);
		}
	}
}
void PlayState::RecordMove(Pos e)
{
	// Add move to last moves
	lastMoves.push_back(new Move(lastPick, e, board[lastPick.files][lastPick.rank]->GetType(), lastMoves.size() + 1));

	// Add the move to the Textlist
	lastMoveList->AddItem(lastMoves[lastMoves.size() - 1]->GetMoveText());
}

void PlayState::Deselect()
{
	// Deselect all pieces
	validMoveCount = 0;
	lastPick = Pos();
}