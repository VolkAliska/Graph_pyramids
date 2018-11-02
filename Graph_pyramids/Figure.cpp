/*Figure.cpp*/

#include "stdafx.h"
#include "Figure.h"
using namespace std;
//const int dk = 10;
//const double dv = 2.0;
//const float PI = 3.14;
//const double UNGLE = 15.0;

HWND hwndf = GetConsoleWindow();
HDC hdcf = GetDC(hwndf);
COLORREF colorf = RGB(180, 0, 20);

Figure::Figure(int n){
	this->n = n;
	kx = 1; ky = 1; kz = 1;
	
}

Matrix Figure::preBrezenhem(Matrix premap, double x1, double y1, double x2, double y2) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	//SetPixel(hdcf, x2, y2, RGB(255, 255, 255));
	premap.matr[SPACE + int(y2)][SPACE + int(x2)] = 2;//граница
	while ((int(x1) != int(x2)) || (int(y1) != int(y2)))
	{
		//SetPixel(hdcf, x1, y1, RGB(255, 255, 255));
		premap.matr[SPACE + int(y1)][SPACE + int(x1)] = 2;
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
	return premap;
}

Matrix Figure::preTriangle(Matrix premap, point p1, point p2, point p3){
	premap = preBrezenhem(premap, p1.x, p1.y, p2.x, p2.y);
	premap = preBrezenhem(premap, p2.x, p2.y, p3.x, p3.y);
	premap = preBrezenhem(premap, p1.x, p1.y, p3.x, p3.y);
	return premap;
}

Matrix Figure::preRectangle(Matrix premap, point p1, point p2, point p3, point p4){
	premap = preBrezenhem(premap, p1.x, p1.y, p2.x, p2.y);
	premap = preBrezenhem(premap, p2.x, p2.y, p3.x, p3.y);
	premap = preBrezenhem(premap, p3.x, p3.y, p4.x, p4.y);
	premap = preBrezenhem(premap, p1.x, p1.y, p4.x, p4.y);
	return premap;
}

Matrix Figure::preColor(Matrix premap, int color){
	int i = 0, j = 0;
	for (i = 0; i < premap.n; i++){
		for (j = 0; j < premap.m; j++){
			if ((premap.matr[i][j] == 2) && (premap.matr[i][j+1] != 2)){
				j++;
				int flag = 0;
				for (int k = j; k < premap.m; k++){
					if (premap.matr[i][k] == 2)
						flag = 1;
				}
				if (flag == 1){
					while (premap.matr[i][j] !=2){// TO DO проверка на мин и макс по ”
						premap.matr[i][j] = color; // наличие цвета
						j++;
						//SetPixel(hdc, j, i, color);
					}
				}
				break;
			}
		}
	}
	return premap;
}

Matrix Figure::getBitmap(Matrix bitmap, Matrix premap){
	for (int i = 0; i<bitmap.n; i++){
		for (int j = 0; j<bitmap.m; j++){
			if (bitmap.matr[i][j] == 0)
				bitmap.matr[i][j] += premap.matr[SPACE + i][SPACE + j];
		}
	}
	return bitmap;
}

void Figure::drawBrezenhem(double x1, double y1, double x2, double y2) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	SetPixel(hdcf, x2, y2, RGB(255, 255, 255));
	//bitmap[y2][x2] = 2;//граница
	while ((int(x1) != int(x2)) || (int(y1) != int(y2)))
	{
		SetPixel(hdcf, x1, y1, RGB(255, 255, 255));
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


Matrix Figure::draw(Matrix bitmap, Matrix premap, Matrix current){
	if (current.n == 4){
		point points[4];
		for(int i = 0; i < n; i++){
			points[i].x = current.matr[i][0];
			points[i].y = current.matr[i][1];
			points[i].z = current.matr[i][2];
		}
		this->drawTriangle(premap, points[0], points[1], points[2]);
		premap = preColor(premap, 3);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[2], points[1], points[3]);
		premap = preColor(premap, 4);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[3], points[1], points[0]);
		premap = preColor(premap, 5);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[0], points[2], points[3]);
		premap = preColor(premap, 6);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
	}
	if (current.n == 5){
		point points[5];
		for(int i = 0; i < n; i++){
			points[i].x = current.matr[i][0];
			points[i].y = current.matr[i][1];
			points[i].z = current.matr[i][2];
		}
		this->drawTriangle(premap, points[0], points[1], points[2]);
		premap = preColor(premap, 3);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[2], points[1], points[3]);
		premap = preColor(premap, 4);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[3], points[1], points[4]);
		premap = preColor(premap, 5);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawTriangle(premap, points[0], points[1], points[4]);
		premap = preColor(premap, 6);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
		this->drawRectangle(premap, points[0], points[2], points[3], points[4]);
		premap = preColor(premap, 7);
		bitmap = getBitmap(bitmap, premap);
		premap.clean();
	}
	return bitmap;
}

Matrix Figure::drawTriangle(Matrix premap, point p1, point p2, point p3){
	drawBrezenhem(p1.x, p1.y, p2.x, p2.y);
	drawBrezenhem(p2.x, p2.y, p3.x, p3.y);
	drawBrezenhem(p1.x, p1.y, p3.x, p3.y);
	premap = preTriangle(premap, p1, p2, p3);
	return premap;
}

Matrix Figure::drawRectangle(Matrix premap, point p1, point p2, point p3, point p4){
	drawBrezenhem(p1.x, p1.y, p2.x, p2.y);
	drawBrezenhem(p2.x, p2.y, p3.x, p3.y);
	drawBrezenhem(p3.x, p3.y, p4.x, p4.y);
	drawBrezenhem(p1.x, p1.y, p4.x, p4.y);
	premap = preRectangle(premap, p1, p2, p3, p4);
	return premap;
}

point Figure::getCenter(Matrix current){
	point center;
	int sumx = 0;
	int sumy = 0;
	int sumz = 0;
	for(int i = 0; i < current.m; i++){
		sumx += current.matr[i][0];
		sumy += current.matr[i][1];
		sumz += current.matr[i][2];
	}
	center.x = sumx / current.m;
	center.y = sumy / current.m;
	center.z = sumz / current.m;
	return center;
}

void Figure::movePositive(Matrix chn, bool dx, bool dy, bool dz){
	if (dx == true){
		chn.matr[3][0] += dk;
	}
	if (dy == true){
		chn.matr[3][1] += dk;
	}
	if (dz == true){
		chn.matr[3][2] += dk;
	}
}

void Figure::moveNegative(Matrix chn, bool dx, bool dy, bool dz){
	if (dx == true){
		chn.matr[3][0] -= dk;
	}
	if (dy == true){
		chn.matr[3][1] -= dk;
	}
	if (dz == true){
		chn.matr[3][2] -= dk;
	}
}

Matrix Figure::makeChanging(Matrix base, Matrix scale, Matrix rotate, point center){
	
	this->norm(base, center);
	int n = base.n;
	int m = base.m;
	Matrix current(n, m);
	current = base.mul(base, rotate);
	current = current.mul(current, scale);
	this->disnorm(base, center);
	this->disnorm(current, center);
	center = this->getCenter(current);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			current.matr[i][j] = int(current.matr[i][j]);
		}
	}
	//current.ShowMatrix();
	//base.ShowMatrix();
	//chn.ShowMatrix();
	system("cls");
	//this->draw(current);
	return current;
}

void Figure::color(Matrix bitmap){
	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(178, 34, 34);
	COLORREF blue = RGB(0, 128, 128);
	COLORREF green = RGB(50, 205, 50);
	COLORREF yellow = RGB(255, 215, 0);
	COLORREF purple = RGB(199, 21, 133);
	COLORREF gray = RGB(105, 105, 105);
	for (int i = 0; i<bitmap.n; i++){
		for (int j = 0; j<bitmap.m; j++){
			if (bitmap.matr[i][j] == 2){
				SetPixel(hdcf, j, i, white);
			}
			if (bitmap.matr[i][j] == 3){
				SetPixel(hdcf, j, i, red);
			}
			if (bitmap.matr[i][j] == 4){
				SetPixel(hdcf, j, i, blue);
			}
			if (bitmap.matr[i][j] == 5){
				SetPixel(hdcf, j, i, green);
			}
			if (bitmap.matr[i][j] == 6){
				SetPixel(hdcf, j, i, yellow);
			}
			if (bitmap.matr[i][j] == 7){
				SetPixel(hdcf, j, i, purple);
			}
			if (bitmap.matr[i][j] == 8){
				SetPixel(hdcf, j, i, gray);
			}
		}
	}
}

Matrix Figure::makeShadmap(Matrix bitmap){
	Matrix shadmap(bitmap.n+SPACE, bitmap.m);
	for (int i = 0; i < bitmap.n; i++){
		for (int j = 0; j < bitmap.m; j++){
			if (bitmap.matr[i][j] != 0){
				shadmap.matr[i+SHADSTEP][j] = 8; // to do нормальный отступ
			}
		}
	}
	return shadmap;
}

void Figure::norm(Matrix base, point center){
	for(int i = 0; i < base.n; i++){
		base.matr[i][0] -= center.x;
		base.matr[i][1] -= center.y;
		base.matr[i][2] -= center.z;
	}
}

void Figure::disnorm(Matrix base, point center){
	for(int i = 0; i < base.n; i++){
		base.matr[i][0] += center.x;
		base.matr[i][1] += center.y;
		base.matr[i][2] += center.z;
	}
}


void Figure::scaleBigger(Matrix chn){
	chn.matr[0][0] *= dv;
    chn.matr[1][1] *= dv;
	chn.matr[2][2] *= dv;
}

void Figure::scaleSmaller(Matrix chn){
	//if(chn.matr[0][0] > 0.08){ // неграмотный костыль
		chn.matr[0][0] /= dv;
		chn.matr[1][1] /= dv;
		chn.matr[2][2] /= dv;
	//}
}

double Figure::getRad(double ung){
	double newung;
	newung = PI * ung / 180.0;
	return newung;
}

Matrix Figure::rotateY(Matrix chn){
	double radun = UNGLE;
	double fi = this->getRad(radun);
	Matrix bufchn(4, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j< 4; j++){
			if(i == j)
				bufchn.matr[i][j] = 1;
		}
	}
	bufchn.matr[0][0] = cos(-fi);
	bufchn.matr[0][2] = sin(-fi);
	bufchn.matr[2][0] = -sin(-fi);
	bufchn.matr[2][2] = cos(-fi);
	chn = chn.mul(chn, bufchn);
	return chn;
}

Matrix Figure::rotateX(Matrix chn){
	double radun = UNGLE;
	double fi = this->getRad(radun);
	Matrix bufchn(4, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j< 4; j++){
			if(i == j)
				bufchn.matr[i][j] = 1;
		}
	}
	bufchn.matr[1][1] = cos(fi);
	bufchn.matr[1][2] = sin(fi);
	bufchn.matr[2][1] = -sin(fi);
	bufchn.matr[2][2] = cos(fi);
	chn = chn.mul(chn, bufchn);
	return chn;
}

Matrix Figure::rotateZ(Matrix chn){
	double radun = UNGLE;
	double fi = this->getRad(radun);
	Matrix bufchn(4, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j< 4; j++){
			if(i == j)
				bufchn.matr[i][j] = 1;
		}
	}
	bufchn.matr[0][0] = cos(fi);
	bufchn.matr[0][1] = sin(fi);
	bufchn.matr[1][0] = -sin(fi);
	bufchn.matr[1][1] = cos(fi);
	chn = chn.mul(chn, bufchn);
	return chn;
}
