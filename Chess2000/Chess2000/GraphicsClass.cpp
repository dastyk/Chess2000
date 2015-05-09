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
	mWidth = screenWidth;
	mHeight = screenHeight;

	// Initialize GDI+.
	Status st = GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	if (st != Ok)
	{
		return false;
	}


	hdc = BeginPaint(mHwnd, &mPs);

	//mDevice = new Graphics(hdc);
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
	// Begin the frame.
	// This consist of creating a backbuffer and clearing the backbuffer.
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = mWidth;
	rect.bottom = mHeight;
	GetClientRect(mHwnd, &rect);


	backbuffDC = CreateCompatibleDC(hdc);

	backbuffer = CreateCompatibleBitmap(hdc, mWidth, mHeight);

	savedDC = SaveDC(backbuffDC);
	SelectObject(backbuffDC, backbuffer);

	mDevice = Graphics::FromHDC(backbuffDC);

	ClearScreen(Color(255, 0, 0, 0));


	//HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	//FillRect(backbuffDC, &rect, hBrush);
	//DeleteObject(hBrush);
	
	return true;
}

bool GraphicsClass::EndFrame()
{

	// Swap the backbuffer to the screen, then delete it.
	BitBlt(hdc, 0, 0, mWidth, mHeight, backbuffDC, 0, 0, SRCCOPY);
	RestoreDC(backbuffDC, savedDC);

	DeleteObject(mDevice);
	DeleteObject(backbuffer);
	DeleteDC(backbuffDC);



	return true;
}

void GraphicsClass::DrawString(WCHAR* text, int x, int y, REAL fontSize)
{
	Font font(&FontFamily(L"Arial"), fontSize);
	LinearGradientBrush brush(Rect(0, 0, 100, 100), Color::Black, Color::Black, LinearGradientModeHorizontal);
	mDevice->DrawString(text, -1, &font, PointF((REAL)x, (REAL)y), &brush);
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

void GraphicsClass::DrawImage(Image* image, int x, int y, int w, int h)
{
	mDevice->DrawImage(image, x, y, w, h);
}
