#ifndef _GRAPHICSOBJECT_H_
#define _GRAPHICSOBJECT_H_

#pragma once
#include "GraphicsClass.h"
#include "InputClass.h"

class GraphicsObject
{
public:
	virtual ~GraphicsObject();

	virtual void Render() = 0;

	bool IsClicked();

protected:
	GraphicsObject();
	GraphicsObject(int x, int y, UINT w, UINT h, Color bc);

	int mPosX, mPosY;
	UINT mWidth, mHeight;
	Color mBackGroundColor;
};

#endif