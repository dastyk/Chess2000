#ifndef _TEXTLABEL_H_
#define _TEXTLABEL_H_

#pragma once
#include "GraphicsObject.h"
class TextLabel :
	public GraphicsObject
{
public:
	TextLabel();
	TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer);

	~TextLabel();

	void Render();
	void Update(int& layer);

private:
	WCHAR* mText;
	REAL mFontSize;
};

#endif