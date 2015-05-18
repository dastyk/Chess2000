#include "ImageClass.h"
#include "PopUpClass.h"

ImageClass::ImageClass() : GraphicsObject(0, 0, 0, 0, Color(0,0,0,0), -1, 0, false, Color(0, 0, 0, 0), false)
{
}

ImageClass::ImageClass(int x, int y, UINT w, UINT h, Color bc, WCHAR* path, int layer) : GraphicsObject(x, y, w, h, bc, layer, 0, false, Color(0, 0, 0, 0),false)
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
void ImageClass::Update(int& layer)
{
		GraphicsObject::Update(layer);
	
}