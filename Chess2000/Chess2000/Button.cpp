#include "Button.h"


Button::Button() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), -1, 0, false, Color(0, 0, 0, 0)), mText(nullptr), mFontSize(0)
{
}

Button::Button(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer,0,false,Color(0,0,0,0)), mText(t), mFontSize(fS)
{
	mHoverIcon = IDC_HAND;
}

Button::~Button()
{

}

void Button::Render()
{
	GraphicsObject::Render();

	GraphicsClass& g = GraphicsClass::GetInstance();

	g.DrawString(mText, mPosX + 5, mPosY + 5, mFontSize);

}

void Button::Update(int& layer)
{
	GraphicsObject::Update(layer);
}