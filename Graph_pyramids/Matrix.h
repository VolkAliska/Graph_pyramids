/* Matrix.h */

#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <cstdlib>
using namespace std; 

class Matrix{
public:
	int n, m;
	double **matr;
	Matrix(int n, int m);
	Matrix();
	//~Matrix();
	Matrix Mul(Matrix base, Matrix change);
	void ShowMatrix();

	//void Norm(point cen);
	//void Back(point cen);

	//friend Matrix operator +(const Matrix m1, const Matrix m2);
};


#endif //MATRIX