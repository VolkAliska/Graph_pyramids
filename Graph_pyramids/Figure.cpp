/*Figure.cpp*/

#include <windows.h> // color pixels
#include <iostream>
#include <cstdlib>
#include "Figure.h"
using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
COLORREF color = RGB(180, 0, 20);

Figure::Figure(int n){
	this->n = n;
}

void Figure::DrawBrezenhem(int x1, int y1, int x2, int y2) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	SetPixel(hdc, x2, y2, RGB(255, 255, 255));
	//bitmap[y2][x2] = 2;//граница
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(hdc, x1, y1, RGB(255, 255, 255));
		//bitmap[y1][x1] = 2;
		const int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

	int i = 1;
}

void Figure::Draw(Matrix current){
	int rows = current.n;
	for (int i = 0; i < (rows - 2); i++){
		// draw 0-1, 1-2, 2-3 ... lines
		int q = i + 1;
		DrawBrezenhem(current.matr[i][0], current.matr[i][1], current.matr[q][0], current.matr[q][1]);
	}
	// draw (n-1)-0 line
	DrawBrezenhem(current.matr[rows - 2][0], current.matr[rows - 2][1], current.matr[0][0], current.matr[0][1]);
	//draw 0,1,2,3... - n line (n is a vertex)	
	for (int i = 0; i < (rows - 1); i++){
		DrawBrezenhem(current.matr[i][0], current.matr[i][1], current.matr[rows-1][0], current.matr[rows-1][1]);
	}
}