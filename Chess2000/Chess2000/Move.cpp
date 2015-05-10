#include "Move.h"

Move::Move()
{
	movedPiece = nullptr;
}

Move::Move(Pos start, Pos end, wchar_t* movedPiece, UINT order)
{
	startSquare = start;
	endSquare = end;
	this->movedPiece = movedPiece;


	WCHAR** letters = new WCHAR*[8];
	letters[0] = L"A";
	letters[1] = L"B";
	letters[2] = L"C";
	letters[3] = L"D";

	letters[4] = L"E";
	letters[5] = L"F";
	letters[6] = L"G";
	letters[7] = L"H";

	// Create the move text
	std::wstringstream outs;

	outs << order << L". " << letters[startSquare.rank] << startSquare.files + 1 << " - " << letters[endSquare.rank] << endSquare.files + 1 << L" " << movedPiece;

	this->moveText = new wchar_t[(outs.str().length() + 1) * 2];
	memcpy(this->moveText, outs.str().c_str(), (outs.str().length() + 1) * 2);

	delete[] letters;

}

Move::~Move()
{
	if (moveText)
	{
		delete[] moveText;
		moveText = nullptr;
	}
}

wchar_t* Move::GetMoveText()
{
	return moveText;
}
