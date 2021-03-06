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


	int GetPosX();
	int GetPosY();

	void SetPosX(int x);
	void SetPosY(int y);

	int GetLayer();
	void SetLayer(int layer);

	UINT GetWidth();
	UINT GetHeight();

	void SetPopUpItem(bool pop);

protected:
	GraphicsObject(int x, int y, UINT w, UINT h, Color bc, int layer, LPCTSTR hoverIcon, bool changeBGOnHover, Color bcHover, bool popUpItem);
	int mLayer;

	virtual void OnEnter();
	virtual void OnExit();

	bool mInFocus;
	LPCTSTR mHoverIcon;
	bool mHovering;
	int mPosX, mPosY;
	UINT mWidth, mHeight;
	Color mBackGroundColor;
	Color mBCHover;
	bool mChangeBGOnHover;
	bool mPopUpItem;
};

#endif