#ifndef _GRAPHICSOBJECT_H_
#define _GRAPHICSOBJECT_H_

#pragma once
#include "GraphicsClass.h"
#include "InputClass.h"

class GraphicsObject
{
public:
	virtual ~GraphicsObject();

	virtual void Update(int& layer) = 0;
	virtual void Render() = 0;

	virtual bool IsClicked();
	virtual bool IsHovering();

	virtual void OnEnter();
	virtual void OnExit();


	void SetPosY(int y);
	UINT GetHeight();

protected:
	GraphicsObject();
	GraphicsObject(int x, int y, UINT w, UINT h, Color bc, int layer);
	int mLayer;


	LPCTSTR mHoverIcon;
	bool mHovering;
	int mPosX, mPosY;
	UINT mWidth, mHeight;
	Color mBackGroundColor;
};

#endif