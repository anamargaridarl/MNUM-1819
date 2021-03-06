// Otimizaçao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
double math_func(double x)
{
	return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}*/

double math_func(double x)
{
	return 0.28*x*x + 0.5*x + 2;
}
	 


void aurea_method(double x1, double x2, bool minimum, double error, double &x, double &y)
{
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double prev_x = 0;
	double x3 = 0;
	double x4 = 0;
	double func_3;
	double func_4;

	while (abs(x1 - x2) > error)
	{
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		func_3 = math_func(x3);
		func_4 = math_func(x4);

		if (minimum)
		{
			if (func_3 < func_4)
				x2 = x4;
			else
				x1 = x3;
		}
		else
		{
			if (func_3 > func_4)
				x2 = x4;
			else
				x1 = x3;
		}

		if (minimum)
			x = x2;
		else
			x = x1;

		y = math_func(x);
	}
		
}


double math_func_x_y(double x, double y)
{
	return sin(y) + ((y*y) / 4) + cos(x) + ((x*x) / 2) - 1;
}


double func_dev_x(double x, double y)
{
	return -1 * sin(x) + (x / 2);
}

double func_dev_y(double x, double y)
{
	return (y / 2) + cos(y);
}

double func_double_x_x(double x, double y)
{
	return 2;
}

double func_double_x_y(double x, double y)
{
	return -2;
}

double func_double_y_x(double x, double y)
{
	return -2;
}

double func_double_y_y(double x, double y)
{
	return 2;
}

double math_func_2_x_y(double x, double y)
{
	return 2 * x * y + 2 * x - pow(x, 2) - 2 * pow(y, 2);
}
double func_2_dev_x(double x, double y)
{
	return 2 * y + 2 - 2 * x;
}

double func_2_dev_y(double x, double y)
{
	return 2 * x - 4 * y;
}


void gradient(double x, double y, double h, bool min, double error, double &xf, double &yf, double &zf)
{
	double prev_x = 0;
	double prev_y = 0;

	do
	{

		prev_x = x;
		prev_y = y;
		x = prev_x - h * func_dev_x(prev_x, prev_y);
		y = prev_y - h * func_dev_y(prev_x, prev_y);


		if (min)
		{
			if (math_func_x_y(x, y) < math_func_x_y(prev_x, prev_y))
				h *= 2;
			else if (math_func_x_y(x, y) > math_func_x_y(prev_x, prev_y))
				h /= 2;
		}
		else
		{
			if (math_func_x_y(x, y) > math_func_x_y(prev_x, prev_y))
				h *= 2;
			else if (math_func_x_y(x, y) < math_func_x_y(prev_x, prev_y))
				h /= 2;
		}
	} while (abs(x - prev_x) > error || abs(y - prev_y) > error);

	xf = x;
	yf = y;
	zf = math_func_x_y(x, y);
}


void quadric(double x, double y, double error, double &xf, double &yf)
{
	double prev_x = 0;
	double prev_y = 0;
	double H;

	while (abs(x - prev_x) > error or abs(y - prev_y) > error)
	{
	prev_x = x;
	prev_y = y;
	H = 1 / (func_double_x_x(prev_x, prev_y) * func_double_y_y(prev_x, prev_y) - (func_double_y_x(prev_x, prev_y)*func_double_x_y(prev_x, prev_y)));
	x = prev_x - H * func_dev_x(prev_x, prev_y);
	y = prev_y - H * func_dev_y(prev_x, prev_y);
	}

	xf = x;
	yf = y;
}


int main()
{
	double x, y, z;

	aurea_method(-1, 0, true, 0.00001, x, y);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;


	gradient(0, 0, 1,true, 0.00001, x, y, z);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;


	quadric(0, 0, 0.00001,x,y);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;



    return 0;
}

