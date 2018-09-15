/* Figure.h */

#ifndef FIGURE
#define FIGURE
#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

class Figure{
public:
	int n; 
	Figure(int n); // n - number of vertexes
	
	void DrawBrezenhem(int x1, int y1, int x2, int y2);
	void Draw(Matrix current);
	void Color();
	void Rotate();
	void Move();
	void Scale();
};

#endif //FIGURE