/*Matrix.cpp*/

#include "stdafx.h"
#include "Matrix.h"
#include "Figure.h"
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
	matr[3][3] = 1;
}

Matrix::Matrix(){
	matr = nullptr;
	n = 0;
	m = 0;
}

void Matrix::clean(){
	for (int i = 0; i < this->n; i++){
		for (int j = 0; j < this->m; j++){
			this->matr[i][j] = 0;
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

Matrix Matrix::mul(Matrix base, Matrix change){
	Matrix res(base.n, base.m);
	
	for (int i = 0; i < base.n; i++){
		for (int j = 0; j < base.m; j++){
			res.matr[i][j] = 0;
		}
	}
	double buf = 0;
	for (int row = 0; row < base.n; row++) {
		for (int col = 0; col < 4; col++) {
			buf = 0;
			for (int inner = 0; inner < 4; inner++) {
				buf += base.matr[row][inner] * change.matr[inner][col];
			}
			//std::cout << res.matr[row][col] << "  ";
			res.matr[row][col] = buf;
		}
		//std::cout << "\n";
	}
	return res;
}

