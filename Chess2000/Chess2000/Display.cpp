#include "Display.h"

#include "SystemClass.h"

Display::Display()
{
}


Display::~Display()
{
}


bool Display::HandleInput()
{
	return true;
}

bool Display::Update(float dt)
{
	return true;
}
bool Display::Render()
{
	return true;
}


void Display::GoToMainMenu()
{
	SystemClass::GetInstance().ChangeState(MAINMENUSTATE);
}