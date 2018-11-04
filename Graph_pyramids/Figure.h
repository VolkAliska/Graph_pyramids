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
	int kx, ky, kz; // for rotation

	//--MAKE BITMAP--

	Matrix preBrezenhem(Matrix premap, double x1, double y1, double x2, double y2);
	Matrix preTriangle(Matrix premap, point p1, point p2, point p3);
	Matrix preRectangle(Matrix premap, point p1, point p2, point p3, point p4);
	Matrix preColor(Matrix premap, int color);
	Matrix getBitmap(Matrix bitmap, Matrix premap);
	
	//--ROBERTS--

	point getN(point p1, point p2, point p3); // нормаль к плоскости, плохо, что как point 
	//принимаем, что тут x, y и z - это координаты вектора, а не точка
	double skalar(point v1,point v2);
	bool isPlaneVisible(point p1, point p2, point p3/*, point L*/); // N - нормаль, L - вектор наблюдателя

	//--DRAW--

	void drawBrezenhem(double x1, double y1, double x2, double y2);
	Matrix draw(Matrix bitmap, Matrix premap, Matrix current);
	Matrix drawTriangle(Matrix premap, point p1, point p2, point p3);
	Matrix drawRectangle(Matrix premap, point p1, point p2, point p3, point p4);
	void color(Matrix bitmap);

	//--SHADOWS--


	//--CHANGES
	void movePositive(Matrix chn, bool dx, bool dy, bool dz);
	void moveNegative(Matrix chn, bool dx, bool dy, bool dz);
	Matrix makeChanging(Matrix base, Matrix scale, Matrix rotate, point center); //clean space, cnahge * base, draw
	void norm(Matrix base, point center);
	void disnorm(Matrix base, point center);
	void scaleBigger(Matrix chn);
	void scaleSmaller(Matrix chn);
	Matrix rotateY(Matrix chn);
	Matrix rotateX(Matrix chn);
	Matrix rotateZ(Matrix chn);
	point getCenter(Matrix current);
	double getRad(double ung);
};

#endif //FIGURE                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             