#include "GraphicsObject.h"

#include "SystemClass.h"
#include "PopUpClass.h"

GraphicsObject::GraphicsObject(int x, int y, UINT w, UINT h, Color bc, int layer, LPCTSTR hoverIcon, bool changeBGOnHover, Color bcHover, bool popUpItem) : mPosX(x), mPosY(y), mWidth(w), mHeight(h), mBackGroundColor(bc), mLayer(layer), mHovering(false), mHoverIcon(hoverIcon), mChangeBGOnHover(changeBGOnHover), mBCHover(bcHover), mInFocus(false), mPopUpItem(popUpItem)
{

}


GraphicsObject::~GraphicsObject()
{
}

void GraphicsObject::Render()
{
	GraphicsClass& g = GraphicsClass::GetInstance();

	g.FillRectangle(mBackGroundColor, mPosX, mPosY, mWidth, mHeight);

	if (mChangeBGOnHover)
		if (mHovering)
			g.FillRectangle(mBCHover, mPosX, mPosY, mWidth, mHeight);

	
}

bool GraphicsObject::IsClicked()
{
	if ((!PopUpClass::IsPopActive) || mPopUpItem)
	{
		int x, y;
		InputClass& i = InputClass::GetInstance();
		if (mHovering)
		{
			if (i.IsMouseKeyDown(LMOUSE))
			{

				i.MouseUp(LMOUSE);
				return true;
			}

		}
	}
	return false;
}


int GraphicsObject::GetPosX()
{
	return mPosX;
}

int GraphicsObject::GetPosY()
{
	return mPosY;
}


void GraphicsObject::SetPosX(int x)
{
	mPosX = x;
}

void GraphicsObject::SetPosY(int y)
{
	mPosY = y;
}


int GraphicsObject::GetLayer()
{
	return mLayer;
}

void GraphicsObject::SetLayer(int layer)
{
	mLayer = layer;
}


UINT GraphicsObject::GetWidth()
{
	return mWidth;
}


UINT GraphicsObject::GetHeight()
{
	return mHeight;
}



void GraphicsObject::SetPopUpItem(bool pop)
{
	mPopUpItem = pop;
}


bool GraphicsObject::IsHovering()
{
	if ((!PopUpClass::IsPopActive) || mPopUpItem)
	{
		int x, y;
		InputClass& i = InputClass::GetInstance();

		i.GetMousePos(x, y);
		if (x >= mPosX && x <= mPosX + mWidth)
		{
			if (y >= mPosY && y <= mPosY + mHeight)
			{
				return true;
			}
		}
	}
	return false;
}

void GraphicsObject::Update(int& layer)
{

	if (IsHovering())
	{
		if (mLayer >= layer)
		{
			layer = mLayer;
			SystemClass::GetInstance().ChangeCursor(mHoverIcon);
		}


	}

	OnEnter();
	OnExit();

}


void GraphicsObject::OnEnter()
{
	if (!mHovering)
	{

		if (IsHovering())
		{
			mInFocus = true;
			mHovering = true;
		}
	}
}

void GraphicsObject::OnExit()
{
	if (mHovering)
	{
		if (!IsHovering())
		{
			mInFocus = false;
			mHovering = false;
		}
	}
}