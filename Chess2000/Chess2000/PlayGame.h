#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_

#pragma once
#include "Display.h"
class PlayGame :
	public Display
{
public:
	~PlayGame();


	bool HandleInput();
	bool Update(float dt);
	bool Render();

	static void CreateInstance();
	static PlayGame* GetInstancePointer();
	static PlayGame& GetInstance();
private:
	PlayGame();
	PlayGame(const PlayGame&);
	PlayGame& operator= (const PlayGame&);


	static PlayGame* mInstance;
	

};

#endif