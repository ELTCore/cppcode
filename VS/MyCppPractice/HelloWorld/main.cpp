#include <windows.h>
#include <gdiplus.h>
#include <iostream>

#pragma comment (lib,"Gdiplus.lib")
using namespace Gdiplus;

int main()
{
	ULONG_PTR token;
	GdiplusStartupInput input;
	GdiplusStartup(&token, &input, NULL);

	Image* image = new Image(L"ellipse.gif");
	int frameCount = image->GetFrameCount(&FrameDimensionTime);
	int delay = 0;
	PropertyItem* pItem = NULL;
	UINT size = image->GetPropertyItemSize(PropertyTagFrameDelay);
	pItem = (PropertyItem*)malloc(size);
	image->GetPropertyItem(PropertyTagFrameDelay, size, pItem);
	delay = *(int*)pItem->value * 10;

	HDC hdc = GetDC(NULL);
	Graphics graphics(hdc);

	int nScreenWidth, nScreenHeight;
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	int posX = 0.5 * (nScreenWidth - image->GetWidth());
	int posY = 0.5 * (nScreenHeight - image->GetHeight());


	while (true)
	{
		for (int i = 0; i < frameCount; i++)
		{
			image->SelectActiveFrame(&FrameDimensionTime, i);
			graphics.DrawImage(image, posX, posY);
			Sleep(delay);
		}
	}

	delete image;
	free(pItem);
	GdiplusShutdown(token);
}