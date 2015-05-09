#ifndef _TEXTLABEL_H_
#define _TEXTLABEL_H_

#pragma once
#include "GraphicsObject.h"
class TextLabel :
	public GraphicsObject
{
public:
	TextLabel();
	TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc);

	~TextLabel();

	void Render();


private:
	WCHAR* mText;
	REAL mFontSize;
};

#endif