#ifndef _IMAGECLASS_H_
#define _IMAGECLASS_H_

#pragma once
#include "GraphicsObject.h"


class ImageClass :
	public GraphicsObject
{
public:
	ImageClass();
	ImageClass(int x, int y, UINT w, UINT h, Color bc, WCHAR* path);
	~ImageClass();

	void Render();

private:
	Image* mImage;
};

#endif