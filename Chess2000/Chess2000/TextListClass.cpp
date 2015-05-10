#include "TextListClass.h"


TextListClass::TextListClass() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), -1, 0, false, Color(0, 0, 0, 0)), mFontSize(0)
{
}

TextListClass::TextListClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer, 0, false, Color(0, 0, 0, 0)), mFontSize(fS)
{
	startListAt = 0;
	endListAt = 0;
	mHoverIcon = IDC_HAND;
	mList = new TextLabel(x, y, w, h, t, fS, bc,layer);
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

	g.FillRectangle(Color(50, 255, 255, 255), mPosX + mWidth - 40, mPosY + mFontSize + 10, 20, mHeight);


	UINT x = 0;
	for (int i = startListAt; i < endListAt; i++)
	{
		mItems[i]->SetPosY(mPosY + mFontSize + 5 + x * 20);
		mItems[i]->Render();
		x++;
	}

}

void TextListClass::AddItem(WCHAR* t)
{
	int count = mItems.size();
	mItems.push_back(new TextLabel(mPosX, mPosY + mFontSize + 10 + count * 20, mWidth, 20, t, 10, Color(0, 0, 0, 0), -1));

	endListAt++;
	if (mFontSize + endListAt * 20  >= mList->GetHeight())
	{
		startListAt++;
	}
}

void TextListClass::OnScroll()
{
	InputClass& i = InputClass::GetInstance();

	if (mList->IsHovering())
	{
		if (i.IsMouseKeyDown(LMOUSE))
		{
			drag += i.GetMousePosYDiff();
			if (drag >= 10)
			{
				endListAt = (startListAt > 0) ? endListAt - 1 : endListAt;
				startListAt = (startListAt > 0) ? startListAt - 1 : 0;

				drag = 0;
			}
			else if (drag <= -10)
			{

				startListAt = (endListAt < mItems.size()) ? startListAt + 1 : startListAt;
				endListAt = (endListAt < mItems.size()) ? endListAt + 1 : endListAt;
				drag = 0;
			}
		}
	}
}

void TextListClass::Update(int& layer)
{
	GraphicsObject::Update(layer);

	OnScroll();
}
