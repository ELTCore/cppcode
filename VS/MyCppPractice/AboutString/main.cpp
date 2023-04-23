#include <iostream>
#include <windows.h>
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;
using namespace std;

int main(int argc, char* argv[])
{
    ULONG_PTR token;
    GdiplusStartupInput input;
    GdiplusStartup(&token, &input, NULL);

    Image* image = new Image(L"ellipse.gif");
    int width = image->GetWidth();
    int height = image->GetHeight();

    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);
    HDC hdcMem = CreateCompatibleDC(hdc);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, width, height);
    SelectObject(hdcMem, hBitmap);

    Graphics graphics(hdcMem);
    graphics.DrawImage(image, 0, 0, width, height);

    BITMAP bitmap;
    GetObject(hBitmap, sizeof(BITMAP), &bitmap);

    int x = (GetSystemMetrics(SM_CXSCREEN) - bitmap.bmWidth) / 2;
    int y = (GetSystemMetrics(SM_CYSCREEN) - bitmap.bmHeight) / 2;

    HDC hdcScreen = GetDC(NULL);
    BitBlt(hdcScreen, x, y, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

    delete image;
    DeleteObject(hBitmap);
    DeleteDC(hdcMem);
    ReleaseDC(hwnd, hdc);
    ReleaseDC(NULL, hdcScreen);

    GdiplusShutdown(token);

    return 0;
}