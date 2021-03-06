// LM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double function2(double x, double y)
{
	return y * y - 2 * x*y - 6 * y + 2 * x*x + 15 + cos(10 * x);
}

double function(double x, double y)
{
	return pow(x + 1, 2) + pow(y - 4, 2);
}
double h_diff_x(double x)
{
	return x + 1;
}

double h_diff_x2(double x)
{
	return (5 * sin(10 * x) - x + 3) / (50 * cos(10 * x) - 1);
}


double h_diff_y(double y)
{
	return y - 4;
}

double h_diff_y2(double x, double y)
{
	return ((50 * cos(10 * x) - 1)*y + 5 * sin(10 * x) + (-50 * x - 150)*cos(10 * x) + 6) / (50 * cos(10 * x) - 1);
}

double diff_x(double x)
{
	return 2 * (x + 1);
}

double diff_x2(double x, double y)
{
	return -2 * y - 10 * sin(10 * x) + 4 * x;

}

double diff_y2(double x, double y)
{
	return 2 * y - 2 * x - 6;
}

double diff_y(double y)
{
	return 2 * (y - 4);
}


void LM(double lambda, double x0, double y0)
{
	double x, y;
	double hLMx, hLMy;
	x = y = 1;

	do
	{
		x0 = x;
		y0 = y;

		hLMx = h_diff_x2(x0) + lambda * diff_x2(x0,y0);
		hLMy = h_diff_y2(x0,y0) + lambda * diff_y2(x0,y0);
		x = x0 - hLMx;
		y = y0 - hLMy;

		if (function2(x, y) < function2(x0, y0))
			lambda /= 2;
		else
			lambda *= 2;

	

		cout << "ola" << endl;
	} while ((abs(x0-x) > 0.01) && (abs(y0-y) > 0.01));

	cout << "x " << x0 << endl;
	cout << "y " << y0 << endl;
}
int main()
{
	//LM(1, 0, 0);
	LM(0.1, 1,1);
    return 0;
}

