#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#pragma once
#include "GraphicsClass.h"
#include "GraphicsObject.h"
#include <vector>

class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual bool Update(float dt) = 0;
	virtual bool Render() = 0;
	virtual bool HandleInput() = 0;

protected:
	std::vector<GraphicsObject*> mMenuItems;
};

#endif