/* Figure.h */

#ifndef FIGURE
#define FIGURE
#include "stdafx.h"
#include "Matrix.h"
//#define MAXSIZE 

using namespace std;

struct point{
	double x, y, z;
};

class Figure{
public:
	int n; 
	Figure(int n); // n - number of vertexes
	//int bitmap[MAXSIZE][MAXSIZE];
	int kx, ky, kz; // for rotation

	//--DRAW--
	void drawBrezenhem(double x1, double y1, double x2, double y2);
	void draw(Matrix current);
	void drawTriangle(point p1, point p2, point p3);
	void drawRectangle(point p1, point p2, point p3, point p4);
	//void Color(COLORREF color);

	//--CHANGES
	void movePositive(Matrix chn, bool dx, bool dy, bool dz);
	void moveNegative(Matrix chn, bool dx, bool dy, bool dz);
	void makeChanging(Matrix chn, Matrix base, point center); //clean space, cnahge * base, draw
	void norm(Matrix base, point center);
	void disnorm(Matrix base, point center);
	void scaleBigger(Matrix chn);
	void scaleSmaller(Matrix chn);
	//void Rotate();//void ScaleBig(Matrix chn);
	point getCenter(Matrix current);
};

#endif //FIGURE