#include "TextLabel.h"


TextLabel::TextLabel()
{
}


TextLabel::TextLabel(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer), mText(t), mFontSize(fS)
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