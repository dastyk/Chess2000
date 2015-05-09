#include "PickState.h"

#include "SystemClass.h"

PickState::PickState()
{
	mMenuItems.push_back(mExitButton = new Button(300, 400, 200, 30, L"Exit Game", 15, Color(255, 100, 100, 100)));
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
	// Check if exit button is clicked.
	if (mExitButton->IsClicked())
		SystemClass::GetInstance().Exit();// if clicked exit application.


	return true;
}

void PickState::StartGame()
{
}
