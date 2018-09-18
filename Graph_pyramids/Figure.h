/* Figure.h */

#ifndef FIGURE
#define FIGURE
#include <iostream>
#include <cstdlib>
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
	
	void DrawBrezenhem(int x1, int y1, int x2, int y2);
	void Draw(Matrix current);
	void Color(COLORREF color);
	void Rotate();
	void Move(Matrix chn, bool dx, bool dy, bool dz);
	void Scale();
	point getCenter(Matrix base);
};

#endif //FIGURE