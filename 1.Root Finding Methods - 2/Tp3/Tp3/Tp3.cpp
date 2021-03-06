// Tp3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x, double y)
{
	return (2 * x*x - x * y - 5 * x + 1);
}

double f2(double x, double y)
{
	return (x + 3 * log(x) - y * y);
}

double df1x(double x, double y)
{
	return (4 * x - y - 5);
}

double df1y(double x)
{
	return (-x);
}

double df2x(double x)
{
	return (1 + (3 / x));
}

double df2y(double y)
{
	return (-2 * y);
}

/////////////////////////////////////////////////////////////////////////////////////////////


//The condition to stop the iterations is the number of steps
void SolveSystem(double x0, double y0, int n) 
{
	double x,y;

	x = (x0 - (f1(x0, y0)*df2y(y0) - f2(x0, y0)*df1y(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));
	y = (y0 - (f2(x0, y0)*df1x(x0, y0) - f1(x0, y0)*df2x(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));

	for (int i = 0; i <= n; i++)
	{
		x0 = x;
		y0 = y;
		x = (x0 - (f1(x0, y0)*df2y(y0) - f2(x0, y0)*df1y(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));
		y = (y0 - (f2(x0, y0)*df1x(x0, y0) - f1(x0, y0)*df2x(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));


		cout << x << endl;
		cout << y << endl;
	}

	cout << x << endl;
	cout << y << endl;
}

//The condition to stop the iterations is when abs(x-x0)/abs(y-y0) < 10^-5
void SolveSystem2(double x0, double y0, double e)
{
	double x, y;

	x = (x0 - (f1(x0, y0)*df2y(y0) - f2(x0, y0)*df1y(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));
	y = (y0 - (f2(x0, y0)*df1x(x0, y0) - f1(x0, y0)*df2x(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));

	while( abs(x-x0) > e && abs(y - y0) > e)
	{
		x0 = x;
		y0 = y;
		x = (x0 - (f1(x0, y0)*df2y(y0) - f2(x0, y0)*df1y(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));
		y = (y0 - (f2(x0, y0)*df1x(x0, y0) - f1(x0, y0)*df2x(x0)) / (df1x(x0, y0)*df2y(y0) - df2x(x0)*df1y(x0)));

		cout << "x" << x << endl;
		cout << "y"<< y << endl;
		cout << endl;
	}

	cout << "x" << x << endl;
	cout << "y" << y << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double df1x1(double x, double y) {
	return (y + 5) / (pow(2, 3 / 2) * sqrt(x*y + 5 * x - 1));
}

double df2x1(double x, double y) {
	return ((3 / x) + 1) / (2 * sqrt(3 * log(x) + x));
}

double df1y1(double x, double y) {
	return x / (pow(2, 3 / 2)*sqrt(x*y + 5 * x - 1));
}

double df2y1() {
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SolveSystem3(double x0, double y0, double e)
{
	int flag = 0;

	//Verify is the sucession is convergent 
	if (abs(df1x1(x0, y0)) < 1)
	{
		if (abs(df2x1(x0,y0)) < 1)
		{
			if (abs(df1y1(x0,y0)) < 1)
			{
				if (abs(df2y1()) < 1)
					flag = 1;
				else
					flag = 0;
			}
			else
				flag = 0;
		}
		else
			flag = 0;
	}
	else
		flag = 0;

	if (flag == 1) //method
	{
		double x, y;
		int step = 1;

		x = sqrt((x0*y0 + 5 * x0 - 1) / 2);
		y = sqrt(x0 + 3 * log(x0));

		cout << step << endl;
		cout << "x" << setprecision(15) << x << endl;
		cout << "y" << setprecision(15) << y << endl;
		cout << endl;


		while (abs(x - x0) > e && abs(y - y0) > e)
		{
			x0 = x;
			y0 = y;

			x = sqrt((x0*y0 + 5 * x0 - 1) / 2);
			y = sqrt(x0 + 3 * log(x0));

			step++;
			cout << step<< endl;
			cout << "x" << x << endl;
			cout << "y" << y << endl;
			cout << endl;
		}

		cout << "Result" << endl;
		cout << "x" << x << endl;
		cout << "y" << y << endl;
	
	}
	else
		cout << "Error" << endl;
}
int main()
{
	int flag = 0;
	double const e1 = pow(10, -5);
	double const e2 = pow(10, -8);

	cout << "1.Newton1" << endl;
	cout << "2.Newton2" << endl;
	cout << "3.Picard1" << endl;

	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		SolveSystem(4, 4, 20);
		break;
	}
	case 2:
	{
		SolveSystem2(4, 4, e1);
		break;
	}
	case 3 :
	{
		SolveSystem3(4, 4, e2);
		break;
	}
	default:
		cout << "Error" << endl;
		break;
	}

    return 0;
}

