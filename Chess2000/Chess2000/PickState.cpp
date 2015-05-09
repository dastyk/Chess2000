#include "PickState.h"

#include "SystemClass.h"

PickState::PickState()
{
	mMenuItems.push_back(mMenuButton = new Button(300, 400, 200, 30, L"Main Menu", 15, Color(255, 100, 100, 100)));

	mMenuItems.push_back(new TextLabel(260, 50, 300, 30, L"Chess 2000", 30, Color(0, 0, 0, 0)));
}


PickState::~PickState()
{
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		delete mMenuItems[i];
		mMenuItems[i] = 0;
	}
}

bool PickState::Update(float dt)
{
	return true;
}


bool PickState::Render()
{

	// Render all the meny items.
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		mMenuItems[i]->Render();
	}

	return true;
}


bool PickState::HandleInput()
{
	// Check if menu button is clicked.
	if (mMenuButton->IsClicked())
		SystemClass::GetInstance().ChangeState(MAINMENUSTATE);// if clicked go to menu.


	return true;
}

void PickState::StartGame()
{
}
