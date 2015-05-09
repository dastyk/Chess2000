#ifndef _VIEWTOURNAMENT_H_
#define _VIEWTOURNAMENT_H_

#pragma once
#include "Display.h"
class ViewTournament :
	public Display
{
public:
	ViewTournament();
	~ViewTournament();

	bool HandleInput();
	bool Update(float dt);
	bool Render();

};

#endif