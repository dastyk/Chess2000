////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
}


GraphicsClass::~GraphicsClass()
{

}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{

	return true;
}


void GraphicsClass::Shutdown()
{

	return;
}


bool GraphicsClass::Frame()
{

	return true;
}


bool GraphicsClass::Render()
{

	return true;
}

GraphicsClass& GraphicsClass::GetInstance()
{
	static GraphicsClass inst;
	return inst;
}