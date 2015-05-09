#include "ImageClass.h"


ImageClass::ImageClass()
{
}

ImageClass::ImageClass(int x, int y, UINT w, UINT h, Color bc, WCHAR* path) : GraphicsObject(x, y, w, h, bc)
{
	mImage = new Image(path);
}

ImageClass::~ImageClass()
{
	delete mImage;
}


void ImageClass::Render()
{
	GraphicsObject::Render();

	GraphicsClass& g = GraphicsClass::GetInstance();

	g.DrawImage(mImage, mPosX, mPosY, mWidth, mHeight);
}
