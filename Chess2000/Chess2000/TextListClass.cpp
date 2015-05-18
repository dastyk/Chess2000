#include "TextListClass.h"

#include "PopUpClass.h"

TextListClass::TextListClass() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), -1, 0, false, Color(0, 0, 0, 0), false), mFontSize(0)
{
}

TextListClass::TextListClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer, 0, false, Color(0, 0, 0, 0), false), mFontSize(fS)
{
	startListAt = 0;
	endListAt = 0;
	mHoverIcon = IDC_HAND;
	mList = new TextLabel(x, y, w, h, t, fS, bc,layer);
	InputClass::GetInstance().AddScrollListener(&drag);
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

	// Check if scroll is needed.
	if (startListAt > 0 || endListAt < mItems.size())
	{
		g.FillRectangle(Color(50, 255, 255, 255), mPosX + mWidth - 40, mPosY + mFontSize + 10, 20, mHeight - (mFontSize + 10));

		// Calculate the dimensions and position of the scroll bar.
		int full = mItems.size();
		int finHeight = ((endListAt - startListAt) / (float)full) * (mHeight - (mFontSize + 10));
		int finPos = mPosY + mFontSize + 10 +  (startListAt / (float) full)*(mHeight - (mFontSize + 10));

		g.FillRectangle(Color(100, 255, 255, 255), mPosX + mWidth - 40, finPos, 20, finHeight);
	}


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
	// Handle the input for the scroll.
	if (mInFocus)
	{
		if (!IsHovering())
		{
			if (!i.IsMouseKeyDown(LMOUSE))
			{
				mInFocus = false;
			}
		}
	}

	if (mInFocus)
	{
		if (i.IsMouseKeyDown(LMOUSE))
		{
			drag += i.GetMousePosYDiff();
		}

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

void TextListClass::Update(int& layer)
{

	GraphicsObject::Update(layer);
	if ((!PopUpClass::IsPopActive) || mPopUpItem)
	{
		OnScroll();
	}
}


void TextListClass::OnEnter()
{
	if (!mHovering)
	{
		if (IsHovering())
		{
			mInFocus = true;
			drag = 0;
			mHovering = true;
		}
	}

}

void TextListClass::OnExit()
{
	if (mHovering)
	{
		if (!IsHovering())
		{
			mHovering = false;
		}
	}

}