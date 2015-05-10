#ifndef _PUPUPCLASS_H_
#define _PUPUPCLASS_H_

#pragma once
#include "GraphicsObject.h"
#include "Button.h"
#include "TextLabel.h"


#define POPUPBUTTON 0
#define POPUPTEXTLABEL 1

class PopUpClass :
	public GraphicsObject
{
public:
	PopUpClass();
	PopUpClass(int x, int y, UINT w, UINT h, WCHAR* t, REAL fS, Color bc, int layer);
	~PopUpClass();

	void Render();
	void Update(int& layer);

	void AddItem(GraphicsObject* item, UINT type);

	int PopUp(int& answer);
	bool IsPop();


	static bool IsPopActive;

private:

	void OnEnter();
	void OnExit();

	int mAnswer;

	TextLabel* mBG;
	TextLabel* mText;

	struct ItemStruct
	{
		GraphicsObject* oItem;
		UINT oType;
		ItemStruct(GraphicsObject* item, UINT type) : oItem(item), oType(type)
		{

		}

	};

	std::vector<ItemStruct> mItems;
};

#endif