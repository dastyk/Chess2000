#ifndef _BUTTON_H_
#define _BUTTON_H_

#pragma once

#include "GraphicsObject.h"

class Button :
	public GraphicsObject
{
public:
	Button();
	Button(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer);
	~Button();

	void Render();
	void Update(int& layer);

private:
	WCHAR* mText;
	REAL mFontSize;
};

#endif

