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
	HDC hdc = BeginPaint(mHwnd, &mPs);
	mDevice = new Graphics(hdc);
	return true;
}


void GraphicsClass::Shutdown()
{
	EndPaint(mHwnd, &mPs);
	// Shutdown GDIplus
	GdiplusShutdown(gdiplusToken);

	return;
}


bool GraphicsClass::BeginFrame()
{


	return true;
}

bool GraphicsClass::EndFrame()
{

	return true;
}

void GraphicsClass::DrawString(WCHAR* text, int x, int y, REAL fontSize)
{
	Font font(&FontFamily(L"Arial"), fontSize);
	LinearGradientBrush brush(Rect(0, 0, 100, 100), Color::Red, Color::Yellow, LinearGradientModeHorizontal);
	Status st = mDevice->DrawString(text, -1, &font, PointF((REAL)x, (REAL)y), &brush);
}

void GraphicsClass::DrawRectangle(Color c, REAL boarderWidth, int x, int y, int w, int h)
{
	Pen pen(c, boarderWidth);

	mDevice->DrawRectangle(&pen, x, y, w, h);
}

void GraphicsClass::FillRectangle(Color c, int x, int y, int w, int h)
{
	SolidBrush brush(c);

	mDevice->FillRectangle(&brush, x, y, w, h);
}

GraphicsClass& GraphicsClass::GetInstance()
{
	static GraphicsClass inst;
	return inst;
}

void GraphicsClass::ClearScreen(Color c)
{
	mDevice->Clear(c);
}