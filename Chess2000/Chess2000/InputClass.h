////////////////////////////////////////////////////////////////////////////////
// Filename: InputClass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_

/////////////
// Defines //
/////////////
#define LMOUSE 1
#define RMOUSE 2
#define MMOUSE 16

////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
#pragma once
class InputClass
{
public:


	void Initialize();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);
	bool GetKeyStateAndReset(unsigned int);

	void OnMouseMove(int, int);
	void MouseDown(unsigned int);
	void MouseUp(unsigned int);

	bool IsMouseKeyDown(unsigned int);
	bool GetMouseKeyStateAndReset(unsigned int);

	void GetMousePos(int &x, int &y);

	static InputClass& GetInstance();

private:
	bool mKeys[256];
	bool mMouseKeys[20];

	int mMousePosX, mMousePosY, mLastMousePosX, mLastMousePosY;

	InputClass();
	InputClass(const InputClass&);
	InputClass& operator= (const InputClass&);
	~InputClass();

};


#endif