#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#pragma once
#include "GraphicsClass.h"

class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual bool Update(float dt);
	virtual bool Render();
	virtual bool HandleInput();

protected:
	GraphicsClass& mGraphics = GraphicsClass::GetInstance();
};

#endif