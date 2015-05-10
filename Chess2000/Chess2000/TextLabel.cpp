#include "TextLabel.h"


TextLabel::TextLabel() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), -1, 0, false, Color(0, 0, 0, 0)), mText(nullptr), mFontSize(0)
{
}


TextLabel::TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer, 0, false, Color(0, 0, 0, 0)), mText(t), mFontSize(fS)
{

}

TextLabel::TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer, LPCTSTR hoverIcon) : GraphicsObject(x, y, w, h, bc, layer, hoverIcon, false, Color(0, 0, 0, 0)), mText(t), mFontSize(fS)
{

}

TextLabel::TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer, LPCTSTR hoverIcon, bool changeBGOnHover, Color bcHover) : GraphicsObject(x, y, w, h, bc, layer, hoverIcon, changeBGOnHover, bcHover), mText(t), mFontSize(fS)
{

}

TextLabel::~TextLabel()
{

}

void TextLabel::Render()
{
	GraphicsObject::Render();

	GraphicsClass& g = GraphicsClass::GetInstance();

	g.DrawString(mText, mPosX + 5, mPosY + 5, mFontSize);

}
void TextLabel::Update(int& layer)
{
	GraphicsObject::Update(layer);
}