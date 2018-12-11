/* (Main)  Graph_pyramids.cpp */

#include "stdafx.h"
#include "Matrix.h"
#include "Figure.h"
using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
COLORREF color = RGB(180, 0, 20);
//
//const float PI = 3.14;
//const double UNGLE = 10.0;
const int k = 16;

int main(){

	Matrix bitmap(HEIGTH, WIDTH);
	bitmap.clean();

	Matrix premap(pmHeigth, pmWidth);
	premap.clean();

	Matrix shadmap(HEIGTH+SPACE, WIDTH);
	shadmap.clean();

	Figure p1(4); // triangle pyramid
	Matrix p1base(4, 4);
	Matrix p1current(4,4);
	Matrix p1scale(4, 4);
	Matrix p1rotate(4, 4);
	Matrix p1pr(4,4);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j){
				p1scale.matr[i][j] = 1;
				p1rotate.matr[i][j] = 1;
			}
		}
	}
	point p1center;
	
	//example 
	p1base.matr[0][0] = 2 * k; p1base.matr[0][1] = 3 * k; p1base.matr[0][2] = 3* k; p1base.matr[0][3] = 1;
	p1base.matr[1][0] = 3.5 * k; p1base.matr[1][1] =  k; p1base.matr[1][2] = 2.5 * k; p1base.matr[1][3] = 1;
	p1base.matr[2][0] = 5 * k; p1base.matr[2][1] = 3 * k; p1base.matr[2][2] = 3 * k; p1base.matr[2][3] = 1;
	p1base.matr[3][0] = 4 * k; p1base.matr[3][1] = 3 * k; p1base.matr[3][2] = k; p1base.matr[3][3] = 1;
	bitmap = p1.draw(bitmap, premap, p1base);
	bitmap.clean();
	//////////
	/*point p1p1, p1p2, p1p3;
	p1p1.x = p1base.matr[0][0];
	p1p1.y = p1base.matr[0][1];
	p1p1.z = p1base.matr[0][2];
	p1p2.x = p1base.matr[1][0];
	p1p2.y = p1base.matr[1][1];
	p1p2.z = p1base.matr[1][2];
	p1p3.x = p1base.matr[2][0];
	p1p3.y = p1base.matr[2][1];
	p1p3.z = p1base.matr[2][2];
	premap = p1.preTriangle(premap, p1p1, p1p2, p1p3);
	premap = p1.preColor(premap);
	bitmap = p1.getBitmap(bitmap, premap);
	for (int i = 0; i < premap.n; i++){
		for (int j = 0; j < premap.m; j++){
			premap.matr[i][j] = 0;
		}
	}
	p1.Color(bitmap);
*/
	//////////
	p1center = p1.getCenter(p1base);

	for (int i = 0; i < p1base.n; i++){
		for (int j = 0; j < p1base.m; j++){
			p1current.matr[i][j] = p1base.matr[i][j];
		}
	}
	p1pr = p1.getProect(p1current);

	Figure p2(5); // rectangle pyramid
	Matrix p2base(5, 4);
	Matrix p2current(5, 4);
	Matrix p2scale(4, 4);
	Matrix p2rotate(4, 4);
	Matrix p2pr(5, 4);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j){
				p2scale.matr[i][j] = 1;
				p2rotate.matr[i][j] = 1;
			}
		}
	}
	point p2center;
	
	p2base.matr[0][0] = 5 * k; p2base.matr[0][1] = 4 * k; p2base.matr[0][2] = 4 * k; p2base.matr[0][3] = 1;
	p2base.matr[1][0] = 6.5 * k; p2base.matr[1][1] = 1 * k; p2base.matr[1][2] = 5 * k; p2base.matr[1][3] = 1;
	p2base.matr[2][0] = 6 * k; p2base.matr[2][1] = 4 * k; p2base.matr[2][2] = 6 * k; p2base.matr[2][3] = 1;
	p2base.matr[3][0] = 8 * k; p2base.matr[3][1] = 4 * k; p2base.matr[3][2] = 6 * k; p2base.matr[3][3] = 1;
	p2base.matr[4][0] = 7 * k; p2base.matr[4][1] = 4 * k; p2base.matr[4][2] = 4 * k; p2base.matr[4][3] = 1;
	bitmap = p2.draw(bitmap, premap, p2base);
	bitmap.clean();
	p2center = p2.getCenter(p2base);

	for (int i = 0; i < p2base.n; i++){
		for (int j = 0; j < p2base.m; j++){
			p2current.matr[i][j] = p2base.matr[i][j];
		}
	}
	p2pr = p2.getProect(p2current);
	//----------
	char mode;
	while(true){
		mode = _getwch();
		if(mode == '2'){
			p1.movePositive(p1scale, true, false, false);
			p1current = p1.makeChanging(p1base, p1scale, p1rotate, p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '3'){
			p1.moveNegative(p1scale, true, false, false);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate ,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '4'){
			p1.movePositive(p1scale, false, true, false);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '5'){
			p1.moveNegative(p1scale, false, true, false);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '6'){
			p1.scaleBigger(p1scale);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '7'){
			p1.scaleSmaller(p1scale);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '8'){
			p1rotate = p1.rotateY(p1rotate);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '9'){
			p1rotate = p1.rotateX(p1rotate);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == '0'){
			p1rotate = p1.rotateZ(p1rotate);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == 'z'){
			p1.movePositive(p1scale, false, false, true);
			p1current = p1.makeChanging(p1base, p1scale, p1rotate, p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		if(mode == 'x'){
			p1.moveNegative(p1scale, false, false, true);
			p1current = p1.makeChanging(p1base,  p1scale, p1rotate ,p1center);
			p1pr = p1.getProect(p1current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p1.color(bitmap);
			bitmap.clean();
			p1center = p1.getCenter(p1base);
		}
		//
		if(mode == 'w'){
			p2.movePositive(p2scale, true, false, false);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
			p2center = p2.getCenter(p2base);
		}
		if(mode == 'e'){
			p2.moveNegative(p2scale, true, false, false);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'r'){
			p2.movePositive(p2scale, false, true, false);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 't'){
			p2.moveNegative(p2scale, false, true, false);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'y'){
			p2.scaleBigger(p2scale);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'u'){
			p2.scaleSmaller(p2scale);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'i'){
			p2rotate = p2.rotateY(p2rotate);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'o'){
			p2rotate = p2.rotateX(p2rotate);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'p'){
			p2rotate = p2.rotateZ(p2rotate);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == 'c'){
			p2.movePositive(p2scale, false, false, true);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
			p2center = p2.getCenter(p2base);
		}
		if(mode == 'v'){
			p2.moveNegative(p2scale, false, false, true);
			p2current = p2.makeChanging(p2base, p2scale, p2rotate, p2center);
			p2center = p2.getCenter(p2base);
			p2pr = p2.getProect(p2current);
			bitmap = p1.draw(bitmap, premap, p1pr);
			bitmap = p2.draw(bitmap, premap, p2pr);
			p2.color(bitmap);
			bitmap.clean();
		}
		if(mode == '1')
			break;
	}
 
	
	_getwch();

	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                