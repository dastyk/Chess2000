////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	mDevice = 0;
}


GraphicsClass::~GraphicsClass()
{

}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	mHwnd = hwnd;

	// Initialize GDI+.
	Status st = GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (st != Ok)
	{
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Shutdown GDIplus
	GdiplusShutdown(gdiplusToken);

	return;
}


bool GraphicsClass::BeginFrame()
{

	HDC hdc = BeginPaint(mHwnd, &mPs);
	mDevice = new Graphics(hdc);


	return true;
}

bool GraphicsClass::EndFrame()
{
	delete mDevice;
	EndPaint(mHwnd, &mPs);

	return true;
}

void GraphicsClass::DrawString(WCHAR* text, int x, int y)
{
	Font font(&FontFamily(L"Arial"), 12);
	LinearGradientBrush brush(Rect(0, 0, 100, 100), Color::Red, Color::Yellow, LinearGradientModeHorizontal);
	Status st = mDevice->DrawString(text, -1, &font, PointF((REAL)x, (REAL)y), &brush);
}


GraphicsClass& GraphicsClass::GetInstance()
{
	static GraphicsClass inst;
	return inst;
}