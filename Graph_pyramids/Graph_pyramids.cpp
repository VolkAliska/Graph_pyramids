/* (Main)  Graph_pyramids.cpp */

#include "stdafx.h"
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
	Figure p1(4); // triangle pyramid
	Matrix p1base(4, 4);
	Matrix p1current(4,4);
	Matrix p1chn(4, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j)
				p1chn.matr[i][j] = 1;
		}
	}
	point p1center;
	
	//example 
	p1base.matr[0][0] = 2 * k; p1base.matr[0][1] = 3.5 * k; p1base.matr[0][2] = k; p1base.matr[0][3] = 1;
	p1base.matr[1][0] = 3 * k; p1base.matr[1][1] = 2.5 * k; p1base.matr[1][2] = 2 * k; p1base.matr[1][3] = 1;
	p1base.matr[2][0] = 4 * k; p1base.matr[2][1] = 3 * k; p1base.matr[2][2] = 3 * k; p1base.matr[2][3] = 1;
	p1base.matr[3][0] = 3*k; p1base.matr[3][1] = k; p1base.matr[3][2] = 2*k; p1base.matr[3][3] = 1;
	p1.draw(p1base);
	p1center = p1.getCenter(p1base);

	for (int i = 0; i < p1base.n; i++){
		for (int j = 0; j < p1base.m; j++){
			p1current.matr[i][j] = p1base.matr[i][j];
		}
	}

	////////////////
	char mode;
	while(true){
		mode = _getwch();
		if(mode == '2'){
			p1.movePositive(p1chn, true, false, false);
			p1.makeChanging(p1base, p1chn, p1center);
		}
		if(mode == '3'){
			p1.moveNegative(p1chn, true, false, false);
			p1.makeChanging(p1base, p1chn,p1center);
		}
		if(mode == '4'){
			p1.movePositive(p1chn, false, true, false);
			p1.makeChanging(p1base, p1chn,p1center);
		}
		if(mode == '5'){
			p1.moveNegative(p1chn, false, true, false);
			p1.makeChanging(p1base, p1chn,p1center);
		}
		if(mode == '6'){
			p1.scaleBigger(p1chn);
			p1.makeChanging(p1base, p1chn,p1center);
		}
		if(mode == '7'){
			p1.scaleSmaller(p1chn);
			p1.makeChanging(p1base, p1chn,p1center);
		}
		if(mode == '1')
			break;
	}
 	Figure p2(5); // pyramid with the rectangle as a foundation
	Matrix p2base(5, 4);
	Matrix p2current(5,4);
	Matrix p2chn(4, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j)
				p1chn.matr[i][j] = 1;
		}
	}

	point p2center;
	//example 
	p2base.matr[0][0] = 5 * k; p2base.matr[0][1] = 3.5 * k; p2base.matr[0][2] = k; p2base.matr[0][3] = 1;
	p2base.matr[1][0] = 6 * k; p2base.matr[1][1] = 1.5 * k; p2base.matr[1][2] = 2 * k; p2base.matr[1][3] = 1;
	p2base.matr[2][0] = 6 * k; p2base.matr[2][1] = 3 * k; p2base.matr[2][2] = 3 * k; p2base.matr[2][3] = 1;
	p2base.matr[3][0] = 7.5 * k; p2base.matr[3][1] = 3.5 * k; p2base.matr[3][2] = 2 * k; p2base.matr[3][3] = 1;
	p2base.matr[4][0] = 6.5 * k; p2base.matr[4][1] = 4.5 * k; p2base.matr[4][2] = 1.5 * k; p2base.matr[4][3] = 1;
	p2.draw(p2base);

	p2center = p2.getCenter(p2base);
	for (int i = 0; i < p2base.n; i++){
		for (int j = 0; j < p2base.m; j++){
			p2current.matr[i][j] = p2base.matr[i][j];
		}
	}
	
	_getwch();

	return 0;
}
