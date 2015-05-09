#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#pragma once

#include "GraphicsObject.h"
#include <vector>

class Display
{

public:
	virtual ~Display();

	virtual bool HandleInput() = 0;
	virtual bool Update(float dt) = 0;
	virtual bool Render() = 0;
	
protected:
	Display();
	void GoToMainMenu();

	std::vector<GraphicsObject*> mMenuItems;
};

#endif