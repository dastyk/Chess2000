#include "GraphicsObject.h"


GraphicsObject::GraphicsObject() 
{
}

GraphicsObject::GraphicsObject(int x, int y, UINT w, UINT h, Color bc) : mPosX(x), mPosY(y), mWidth(w), mHeight(h), mBackGroundColor(bc)
{

}


GraphicsObject::~GraphicsObject()
{
}

void GraphicsObject::Render()
{
	GraphicsClass& g = GraphicsClass::GetInstance();

	g.FillRectangle(mBackGroundColor, mPosX, mPosY, mWidth, mHeight);
}

bool GraphicsObject::IsClicked()
{
	int x, y;
	InputClass& i = InputClass::GetInstance();
	if (i.IsMouseKeyDown(LMOUSE))
	{
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