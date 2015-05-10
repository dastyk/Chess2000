#include "Display.h"

#include "SystemClass.h"

Display::Display()
{
}


Display::~Display()
{
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		delete mMenuItems[i];
		mMenuItems[i] = 0;
	}
}


bool Display::HandleInput()
{
	return true;
}

bool Display::Update(float dt)
{
	int layer = 0;

	// Update all menuitems.
	int items = mMenuItems.size() ;
	for (int i = 0; i < items; i++)
	{
		mMenuItems[i]->Update(layer);
	}

	return true;
}
bool Display::Render()
{

	// Render all the meny items.
	UINT items = mMenuItems.size();
	for (UINT i = 0; i < items; i++)
	{
		mMenuItems[i]->Render();
	}




	return true;
}


void Display::GoToMainMenu()
{
	SystemClass::GetInstance().ChangeState(MAINMENUSTATE);
}