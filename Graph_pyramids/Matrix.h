/* Matrix.h */


#ifndef MATRIX
#define MATRIX
#include "stdafx.h"
using namespace std; 

class Matrix{
public:
	int n, m; // n - rows, m - columns
	double **matr;
	Matrix(int n, int m);
	Matrix();
	//~Matrix();
	Matrix mul(Matrix base, Matrix change);
	void ShowMatrix();

	//void Norm(point cen);
	//void Back(point cen);

	//friend Matrix operator +(const Matrix m1, const Matrix m2);
};


#endif //MATRIX