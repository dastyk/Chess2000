#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#pragma once



class Display
{

public:
	virtual ~Display();

	virtual bool HandleInput();
	virtual bool Update(float dt);
	virtual bool Render();
	
protected:
	Display();


	void GoToMainMenu();
};

#endif