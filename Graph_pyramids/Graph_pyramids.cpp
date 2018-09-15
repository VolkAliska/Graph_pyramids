/* (Main)  Graph_pyramids.cpp */

#include <windows.h> // color pixels
#include <iostream>
#include <cmath> // matrix
#include <stdlib.h>
#include "Matrix.h"
#include "Figure.h"
using namespace std;
//
//HWND hwnd = GetConsoleWindow();
//HDC hdc = GetDC(hwnd);
//COLORREF color = RGB(180, 0, 20);

const float PI = 3.14;
const double UNGLE = 10.0;
const int k = 60;

int main(){
	Figure p1(4); // pyramid with the triangle as a foundation
	Matrix p1base(4, 4);
	//example 
	p1base.matr[0][0] = 2 * k; p1base.matr[0][1] = 4.5 * k; p1base.matr[0][2] = k; p1base.matr[0][3] = 1;
	p1base.matr[1][0] = 3 * k; p1base.matr[1][1] = 3.5 * k; p1base.matr[1][2] = 2 * k; p1base.matr[1][3] = 1;
	p1base.matr[2][0] = 4 * k; p1base.matr[2][1] = 4 * k; p1base.matr[2][2] = 3 * k; p1base.matr[2][3] = 1;
	p1base.matr[3][0] = 3*k; p1base.matr[3][1] = 2 * k; p1base.matr[3][2] = 2*k; p1base.matr[3][3] = 1;
	p1.Draw(p1base);
	return 0;
}
