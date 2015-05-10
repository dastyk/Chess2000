#pragma once
#include "GraphicsObject.h"
#ifndef _TEXTLISTCLASS_H_
#define _TEXTLISTCLASS_H_

#include <vector>
#include "TextLabel.h"

class TextListClass :
	public GraphicsObject
{
public:
	TextListClass();
	TextListClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc);
	~TextListClass();

	void Render();

	void AddItem(WCHAR* t);

private:
	TextLabel* mList;
	REAL mFontSize;

	std::vector<TextLabel*> mItems;

};

#endif