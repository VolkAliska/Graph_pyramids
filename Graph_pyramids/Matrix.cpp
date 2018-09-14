/*Matrix.cpp*/

#include <ostream>
#include <iostream>
#include <cstdlib>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int n, int m)
{
	this->n = n;
	this->m = m;
	int i, j;
	int size = n * m;
	matr = new double*[n];
	for (i = 0; i < n; i++){
		matr[i] = new double[m];
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			matr[i][j] = 0;
		}
	}
}

void Matrix::ShowMatrix(){
	int i, j;
	for (i = 0; i<n; i++){
		for (j = 0; j<m; j++){
			cout << matr[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
}

Matrix Matrix::Mul(Matrix base, Matrix change){
	Matrix res(base.n, base.m);
	for (int i = 0; i < base.n; i++){
		for (int j = 0; j < base.m; j++){
			res.matr[i][j] = 0;
		}
	}
	for (int row = 0; row < base.n; row++) {
		for (int col = 0; col < base.m; col++) {
			for (int inner = 0; inner < change.n; inner++) {
				res.matr[row][col] += base.matr[row][inner] * change.matr[inner][col];
			}
			std::cout << res.matr[row][col] << "  ";
		}
		std::cout << "\n";
	}
	return res;
}