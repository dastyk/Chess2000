#ifndef _NEWTOURNAMENT_H_
#define _NEWTOURNAMENT_H_

#pragma once
#include "Display.h"
#include "InputClass.h"
#include "SystemClass.h"
#include <windows.h>

class NewTournament :
	public Display
{
public:
	NewTournament();
	~NewTournament();

	bool HandleInput();
	bool Update(float dt);
	bool Render();

private:

};

#endif