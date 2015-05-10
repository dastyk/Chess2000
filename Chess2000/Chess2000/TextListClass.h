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
	TextListClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer);
	~TextListClass();

	void Render();
	void Update(int& layer);

	void AddItem(WCHAR* t);

	void OnScroll();



private:

	virtual void OnEnter();
	virtual void OnExit();


	TextLabel* mList;
	REAL mFontSize;

	UINT startListAt;
	UINT endListAt;

	int drag;

	std::vector<TextLabel*> mItems;

};

#endif