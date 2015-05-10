#include "PopUpClass.h"

bool PopUpClass::IsPopActive = false;

PopUpClass::PopUpClass() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), 20, IDC_ARROW, false, Color(0, 0, 0, 0), true), mAnswer(-1)
{
	mBG = new TextLabel(0, 0, 800, 600, NULL, 0, Color(0, 0, 0, 0), 20);
}

PopUpClass::PopUpClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer + 20, IDC_ARROW, false, Color(0, 0, 0, 0), true), mAnswer(-1)
{
	mBG = new TextLabel(0, 0, 800, 600, NULL, 0, Color(0, 0, 0, 0), layer + 20);
	mText = new TextLabel(mPosX, mPosY, mWidth, fS + 15, t, fS, Color(100, 255, 255, 255), layer + 20, 0, false, Color(0, 0, 0, 0), true);
}



PopUpClass::~PopUpClass()
{
	int count = mItems.size();
	for (int i = 0; i < count; i++)
	{
		delete mItems[i].oItem;
		mItems[i].oItem = nullptr;
	}

	if (mBG)
	{
		delete mBG;
		mBG = 0;
	}
	if (mText)
	{
		delete mText;
		mText = 0;
	}
}

void PopUpClass::Render()
{
	if (mInFocus)
	{
		GraphicsObject::Render();

		GraphicsClass& g = GraphicsClass::GetInstance();

		mText->Render();

		int count = mItems.size();
		for (int i = 0; i < count; i++)
		{
			mItems[i].oItem->Render();

		}
	}
}

void PopUpClass::Update(int& layer)
{
	if (mInFocus)
	{
		GraphicsObject::Update(layer);
		int buttonCount = -1;
		int count = mItems.size();
		for (int i = 0; i < count; i++)
		{
			mItems[i].oItem->Update(layer);
			if (mItems[i].oType == POPUPBUTTON)
			{
				buttonCount++;
				if (mItems[i].oItem->IsClicked())
				{
					mAnswer = buttonCount;
				}
			}		
		}
	}
}

void PopUpClass::AddItem(GraphicsObject* item, UINT type)
{
	item->SetPosX(item->GetPosX() + mPosX);
	item->SetPosY(item->GetPosY() + mPosY);
	item->SetLayer(item->GetLayer() + mLayer);
	item->SetPopUpItem(true);

	mItems.push_back(ItemStruct(item, type));
}


void PopUpClass::OnEnter()
{
	if (!mHovering)
	{
		if (IsHovering())
		{
			mHovering = true;
		}
	}

}

void PopUpClass::OnExit()
{
	if (mHovering)
	{
		if (!IsHovering())
		{
			mHovering = false;
		}
	}

}


int PopUpClass::PopUp(int& answer)
{
	if (mInFocus)
	{
		if (mAnswer >= 0)
		{
			answer = mAnswer;
			mAnswer = -1;
			IsPopActive = false;
			mInFocus = false;
			return 1;
		}
	}
	else if (!IsPopActive)
	{

		IsPopActive = true;
		mInFocus = true;
		return 0;
	}
	
	return -1;
}

bool PopUpClass::IsPop()
{
	return mInFocus;
}
