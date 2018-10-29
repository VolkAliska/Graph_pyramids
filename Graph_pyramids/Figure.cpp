/*Figure.cpp*/

#include "stdafx.h"
#include "Figure.h"
using namespace std;
const int dk = 10;
const double dv = 2.0;
const float PI = 3.14;
const double UNGLE = 15.0;

HWND hwndf = GetConsoleWindow();
HDC hdcf = GetDC(hwndf);
COLORREF colorf = RGB(180, 0, 20);

Figure::Figure(int n){
	this->n = n;
	kx = 1; ky = 1; kz = 1;

	/*for (int i = 0; i < MAXSIZE; i++){
		for(int j = 0; j < MAXSIZE; j++){
			bitmap[i][j] = 0;
		}
	}*/
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

void Figure::draw(Matrix current){
	if (current.n == 4){
		point points[4];
		for(int i = 0; i < n; i++){
			points[i].x = current.matr[i][0];
			points[i].y = current.matr[i][1];
			points[i].z = current.matr[i][2];
		}
		this->drawTriangle(points[0], points[1], points[2]);
		this->drawTriangle(points[2], points[1], points[3]);
		this->drawTriangle(points[3], points[1], points[0]);
		this->drawTriangle(points[0], points[2], points[3]);
	}
	if (current.n == 5){
		point points[5];
		for(int i = 0; i < n; i++){
			points[i].x = current.matr[i][0];
			points[i].y = current.matr[i][1];
			points[i].z = current.matr[i][2];
		}
		this->drawTriangle(points[0], points[1], points[2]);
		this->drawTriangle(points[2], points[1], points[3]);
		this->drawTriangle(points[3], points[1], points[4]);
		this->drawTriangle(points[0], points[1], points[4]);
		this->drawRectangle(points[0], points[2], points[3], points[4]);
	}
}

void Figure::drawTriangle(point p1, point p2, point p3){
	drawBrezenhem(p1.x, p1.y, p2.x, p2.y);
	drawBrezenhem(p2.x, p2.y, p3.x, p3.y);
	drawBrezenhem(p1.x, p1.y, p3.x, p3.y);
}

void Figure::drawRectangle(point p1, point p2, point p3, point p4){
	drawBrezenhem(p1.x, p1.y, p2.x, p2.y);
	drawBrezenhem(p2.x, p2.y, p3.x, p3.y);
	drawBrezenhem(p3.x, p3.y, p4.x, p4.y);
	drawBrezenhem(p1.x, p1.y, p4.x, p4.y);
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

void Figure::makeChanging(Matrix base, Matrix scale, Matrix rotate, point center){
	
	this->norm(base, center);
	int n = base.n;
	int m = base.m;
	Matrix current(n, m);
	//base.ShowMatrix();
	current = base.mul(base, scale);
	//current.ShowMatrix();
	current = current.mul(current, rotate);
	//rotate.ShowMatrix();
	//current.ShowMatrix();
	this->disnorm(base, center);
	this->disnorm(current, center);
	center = this->getCenter(current);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			current.matr[i][j] = int(current.matr[i][j]);
		}
	}
	//current.ShowMatrix();
	//base.ShowMatrix();
	//chn.ShowMatrix();
	system("cls");
	this->draw(current);
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
