#include "TextListClass.h"


TextListClass::TextListClass()
{
}

TextListClass::TextListClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc) : GraphicsObject(x, y, w, h, bc), mFontSize(fS)
{
	mList = new TextLabel(x, y, w, h, t, fS, bc);
}

TextListClass::~TextListClass()
{
	if (mList)
	{
		delete mList;
		mList = 0;
	}

	int count = mItems.size();
	for (int i = 0; i < count; i++)
	{
		delete mItems[i];
		mItems[i] = 0;
	}
}

void TextListClass::Render()
{
	GraphicsObject::Render();

	GraphicsClass& g = GraphicsClass::GetInstance();

	mList->Render();

	int count = mItems.size();
	for (int i = 0; i < count; i++)
	{
		mItems[i]->Render();
	}

}

void TextListClass::AddItem(WCHAR* t)
{
	int count = mItems.size();
	mItems.push_back(new TextLabel(mPosX, mPosY + mFontSize + 5 + count*20, mWidth, 20, t, 10, Color(0, 0, 0, 0)));
}