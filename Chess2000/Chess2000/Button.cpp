#include "Button.h"


Button::Button()
{
}

Button::Button(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc) : GraphicsObject(x, y, w, h, bc), mText(t), mFontSize(fS)
{

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
