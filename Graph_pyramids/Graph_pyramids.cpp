/* (Main)  Graph_pyramids.cpp */

#include <windows.h> // color pixels
#include <iostream>
#include <cmath> // matrix
#include <stdlib.h>
#include "Matrix.h"
#include "Figure.h"
using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
COLORREF color = RGB(180, 0, 20);

const float PI = 3.14;
const double UNGLE = 10.0;
const int k = 16;

int main(){
	Figure p1(4); // pyramid with the triangle as a foundation
	Matrix p1base(4, 4);
	point p1center;
	p1center = p1.getCenter();
	//example 
	p1base.matr[0][0] = 2 * k; p1base.matr[0][1] = 3.5 * k; p1base.matr[0][2] = k; p1base.matr[0][3] = 1;
	p1base.matr[1][0] = 3 * k; p1base.matr[1][1] = 2.5 * k; p1base.matr[1][2] = 2 * k; p1base.matr[1][3] = 1;
	p1base.matr[2][0] = 4 * k; p1base.matr[2][1] = 3 * k; p1base.matr[2][2] = 3 * k; p1base.matr[2][3] = 1;
	p1base.matr[3][0] = 3*k; p1base.matr[3][1] = k; p1base.matr[3][2] = 2*k; p1base.matr[3][3] = 1;
	p1.Draw(p1base);

	Figure p2(5); // pyramid with the rectangle as a foundation
	Matrix p2base(5, 4);
	point p2center;
	p2center = p2.getCenter();
	//example 
	p2base.matr[0][0] = 5 * k; p2base.matr[0][1] = 3.5 * k; p2base.matr[0][2] = k; p2base.matr[0][3] = 1;
	p2base.matr[1][0] = 6 * k; p2base.matr[1][1] = 2.5 * k; p2base.matr[1][2] = 2 * k; p2base.matr[1][3] = 1;
	p2base.matr[2][0] = 7.5 * k; p2base.matr[2][1] = 3.5 * k; p2base.matr[2][2] = 3 * k; p2base.matr[2][3] = 1;
	p2base.matr[3][0] = 6.5 * k; p2base.matr[3][1] = 4.5 * k; p2base.matr[3][2] = 2 * k; p2base.matr[3][3] = 1;
	p2base.matr[4][0] = 6 * k; p2base.matr[4][1] = k; p2base.matr[4][2] = 2 * k; p2base.matr[4][3] = 1;
	p2.Draw(p2base);

	char modeShape;
	while (1){
		modeShape = _getwch();
		switch (modeShape){
		case '1': // triangle pyramid
			char modeAct;
			modeAct = _getwch();

			if (modeAct == 1){  //rotate
				char mode;
				while (1){
					mode = _getwch();
					switch (mode){
					case '1': // X
						break;
					case '2': // Y
						break;
					case '3': // Z
						break;
					}
				}
			}

			if (modeAct == 2){  //move
				char mode;
				while (1){
					mode = _getwch();
					switch (mode){
					case '1': // X
						break;
					case '2': // Y
						break;
					case '3': // Z
						break;
					}
				}
			}

			if (modeAct == 3){  //scale
				char mode;
				while (1){
					mode = _getwch();
					switch (mode){
					case '1': // big
						break;
					case '2': // small
						break;
					}
				}
			}

			if (modeAct == 4){  //escape
				break;
			}

		case '2': // rectangle pyramid
			break;
		}
	}
	_getwch();

	return 0;
}
