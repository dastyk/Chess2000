#include "PopUpClass.h"


PopUpClass::PopUpClass() : GraphicsObject(0, 0, 0, 0, Color(0, 0, 0, 0), 20, IDC_ARROW, false, Color(0, 0, 0, 0)), mAnswer(-1)
{
	mBG = new TextLabel(0, 0, 800, 600, NULL, 0, Color(0, 0, 0, 0), 20);
}

PopUpClass::PopUpClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer) : GraphicsObject(x, y, w, h, bc, layer + 20, IDC_ARROW, false, Color(0, 0, 0, 0)), mAnswer(-1)
{
	mBG = new TextLabel(0, 0, 800, 600, NULL, 0, Color(0, 0, 0, 0), layer + 20);
}



PopUpClass::~PopUpClass()
{
	int count = mItems.size();
	for (int i = 0; i < count; i++)
	{
		delete mItems[i].oItem;
		mItems[i].oItem = nullptr;
	}
}

void PopUpClass::Render()
{
	if (mInFocus)
	{
		GraphicsObject::Render();

		GraphicsClass& g = GraphicsClass::GetInstance();

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

		int count = mItems.size();
		for (int i = 0; i < count; i++)
		{
			mItems[i].oItem->Update(layer);
			if (mItems[i].oItem->IsClicked())
			{

			}
		}
	}
}

void PopUpClass::AddItem(GraphicsObject* item, UINT type)
{
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