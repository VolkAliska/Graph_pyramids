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
	p1.Draw(p1base);
	p1center = p1.getCenter(p1base);

	for (int i = 0; i < p1base.n; i++){
		for (int j = 0; j < p1base.m; j++){
			p1current.matr[i][j] = p1base.matr[i][j];
		}
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
	p2base.matr[1][0] = 6 * k; p2base.matr[1][1] = 2.5 * k; p2base.matr[1][2] = 2 * k; p2base.matr[1][3] = 1;
	p2base.matr[2][0] = 7.5 * k; p2base.matr[2][1] = 3.5 * k; p2base.matr[2][2] = 3 * k; p2base.matr[2][3] = 1;
	p2base.matr[3][0] = 6.5 * k; p2base.matr[3][1] = 4.5 * k; p2base.matr[3][2] = 2 * k; p2base.matr[3][3] = 1;
	p2base.matr[4][0] = 6 * k; p2base.matr[4][1] = k; p2base.matr[4][2] = 2 * k; p2base.matr[4][3] = 1;
	p2.Draw(p2base);

	p2center = p2.getCenter(p2base);
	for (int i = 0; i < p2base.n; i++){
		for (int j = 0; j < p2base.m; j++){
			p2current.matr[i][j] = p2base.matr[i][j];
		}
	}
	int flag = 0;
	int flagaction = 0;
	int flagfigure = 0;
	char mode;
	char modeShape;
	while (1){
		modeShape = _getwch();
		switch (modeShape){
		case '1': // triangle pyramid
			char modeAct;
			while (1){
				modeAct = _getwch();
				switch (modeAct){
				case'1':  //rotate
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // X
							//break;
						case '2': // Y
							//break;
						case '3': // Z
							//break;
						case'4':
							break;
						}
					}
					break;
				case'2':  //move
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // X right
								p1.Move(p1chn, true, false, false);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] = p1base.matr[i][0] + p1chn.matr[0][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '2': // X left
							p1.DisMove(p1chn, true, false, false);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] = p1base.matr[i][0] + p1chn.matr[0][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '3': // Y down
							p1.Move(p1chn, false, true, false);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][1] = p1base.matr[i][1] + p1chn.matr[1][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '4': // Y up
							p1.DisMove(p1chn, false, true, false);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][1] = p1base.matr[i][1] + p1chn.matr[1][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '5': // Z 1
							p1.Move(p1chn, false, false, true);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][2] = p1base.matr[i][2] + p1chn.matr[2][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '6': // Z 2
							p1.DisMove(p1chn, false, false, true);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][2] = p1base.matr[i][2] + p1chn.matr[2][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '7':
							flag = 1;
							break;
						}
						if (flag){
							flag = 0;
							break;
						}
					}
					break;
				case '3': //scale
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // big
							p1.ScaleBig(p1chn);
							for (int i = 0; i < p1base.n; i++){
								p1base.matr[i][0] -= p1center.x;
								p1base.matr[i][1] -= p1center.y;
								p1base.matr[i][2] -= p1center.z;
							}
							point curc;
							curc = p1.getCenter(p1current);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] = p1base.matr[i][0] * p1chn.matr[3][3];
								p1current.matr[i][1] = p1base.matr[i][1] * p1chn.matr[3][3];
								p1current.matr[i][2] = p1base.matr[i][2] * p1chn.matr[3][3];
							}
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] += p1center.x;
								p1current.matr[i][1] += p1center.y;
								p1current.matr[i][2] += p1center.z;
								p1base.matr[i][0] += p1center.x;
								p1base.matr[i][1] += p1center.y;
								p1base.matr[i][2] += p1center.z;
							}
							curc = p1.getCenter(p1current);
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '2': // small
							p1.ScaleSmall(p1chn);
							for (int i = 0; i < p1base.n; i++){
								p1base.matr[i][0] -= p1center.x;
								p1base.matr[i][1] -= p1center.y;
								p1base.matr[i][2] -= p1center.z;
							}
							curc = p1.getCenter(p1current);
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] = p1base.matr[i][0] * p1chn.matr[3][3];
								p1current.matr[i][1] = p1base.matr[i][1] * p1chn.matr[3][3];
								p1current.matr[i][2] = p1base.matr[i][2] * p1chn.matr[3][3];
							}
							for (int i = 0; i < p1base.n; i++){
								p1current.matr[i][0] += p1center.x;
								p1current.matr[i][1] += p1center.y;
								p1current.matr[i][2] += p1center.z;
								p1base.matr[i][0] += p1center.x;
								p1base.matr[i][1] += p1center.y;
								p1base.matr[i][2] += p1center.z;
							}
							curc = p1.getCenter(p1current);
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '3':
							flag = 1;
						}
						if (flag){
							flag = 0;
							break;
						}
					}
					break;
				case'4': //escape
					flagaction = 1;
					break;
				}
				if (flagaction){
					flagaction = 0;
					break;
				}
			}
			break;
		case '2': // rectangle pyramid
			//char modeAct;
			while (1){
				modeAct = _getwch();
				switch (modeAct){
				case'1':  //rotate
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // X
							//break;
						case '2': // Y
							//break;
						case '3': // Z
							//break;
						case'4':
							break;
						}
					}
					break;
				case'2':  //move
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // X right
							p2.Move(p2chn, true, false, false);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][0] = p2base.matr[i][0] + p2chn.matr[0][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '2': // X left
							p2.DisMove(p2chn, true, false, false);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][0] = p2base.matr[i][0] + p2chn.matr[0][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '3': // Y down
							p2.Move(p2chn, false, true, false);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][1] = p2base.matr[i][1] + p2chn.matr[1][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '4': // Y up
							p2.DisMove(p2chn, false, true, false);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][1] = p2base.matr[i][1] + p2chn.matr[1][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '5': // Z 1
							p2.Move(p2chn, false, false, true);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][2] = p2base.matr[i][2] + p2chn.matr[2][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '6': // Z 2
							p2.DisMove(p1chn, false, false, true);
							for (int i = 0; i < p2base.n; i++){
								p2current.matr[i][2] = p2base.matr[i][2] + p2chn.matr[2][3];
							}
							/*p1base.ShowMatrix();
							p1chn.ShowMatrix();
							p1current.ShowMatrix();*/
							system("cls");
							p1.Draw(p1current);
							p2.Draw(p2current);
							break;
						case '7':
							flag = 1;
							break;
						}
						if (flag){
							flag = 0;
							break;
						}
					}
					break;
				case '3': //scale
					while (1){
						mode = _getwch();
						switch (mode){
						case '1': // big
							break;
						case '2': // small
							break;
						}
					}
					break;
				case'4': //escape
					flagaction = 1;
					break;
				}
				if (flagaction){
					flagaction = 0;
					break;
				}
			}
			break;
		}
	}
	_getwch();

	return 0;
}
