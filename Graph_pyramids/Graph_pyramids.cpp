#include <windows.h> // color pixels
#include <iostream>
#include <cmath> // matrix
#include <stdlib.h>
using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
COLORREF color = RGB(180, 0, 20);

const float PI = 3.14;
const double UNGLE = 10.0;
