/* Matrix.h */

#ifndef MATRIX
#define MATRIX
#include <ostream>
#include <iostream>
#include <cstdlib>
using namespace std; 

class Matrix
{
public:
	int n, m;
	double **matr;
	Matrix(int n, int m);
	//~Matrix();
	Matrix Mul(Matrix base, Matrix change);
	void ShowMatrix();
};


#endif //MATRIX