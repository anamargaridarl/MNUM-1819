// TP5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dy(double x, double y)
{
	return x*x + y * y;
}

double py1(double h, double x, double y)
{
	return h * dy(x, y);
}

double py2(double h, double x, double y)
{
	double result;
	double xi = (h / 2) + x;
	result = h * dy( xi , y + ((py1(h, x, y)) / 2 ) );
	return result;
}

double py3(double h, double x, double y)
{
	return h * (dy((h / 2) + x, y + ((py2(h, x, y)) / 2)));
}

double py4(double h, double x, double y)
{
	return h * dy(h + x, y + py3(h, x, y));
}


double Rk2(double x0, double y0, double h, double xf)
{
	double x, y;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + h * dy(x0 + (h/2), y0+ (h/2)*dy(x0,y0));

		x0 = x;
		y0 = y;
	}

	return y0;
}

double Rk4(double x0, double y0, double h, double xf)
{
	double x, y;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + (py1(h, x0, y0) / 6) + (py2(h, x0, y0) / 3) + (py3(h, x0, y0) / 3) + (py4(h, x0, y0) / 6);

		x0 = x;
		y0 = y;
	}

	return y0;

}

double Rk4(double x0, double y0, double h, double xf)
{
	double x, y;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + (py1(h, x0, y0) / 6) + (py2(h, x0, y0) / 3) + (py3(h, x0, y0) / 3) + (py4(h, x0, y0) / 6);

		x0 = x;
		y0 = y;
	}

	return y0;

}


double EulerMethod(double x0, double y0, double h, double xf)
{
	double x, y;

	while (x0 <= xf)
	{
		x = x0 + h;
		y = y0 + h * dy(x0, y0);


		x0 = x;
		y0 = y;
	}

	return y0;
}

double quocient(double s, double sl, double sll)
{
	return (sl - s) / (sll - sl);
}

double eulerError(double sll, double sl)
{
	return sll - sl;
}

double Rk2error(double sll, double sl)
{
	return (sll - sl) / 3;
}

double Rk4error(double sll, double sl)
{
	return (sll - sl) / 15;
}

int main()
{
	double s, sl, sll;
	int flag = 0;
	double const e = 0.001;

	cout << "1. Euler" << endl;
	//cout << "2. Newton Method" << endl;
	cout << "2. Rk2" << endl;
	cout << "3. Rk4" << endl;


	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		//double x0, y0, xf, h;

		s = EulerMethod(0, 0, 0.1, 1.3999);
		cout << "s " <<s <<endl;

		sl = EulerMethod(0, 0, 0.05, 1.3999);
		cout <<"sl " << sl<<endl;


		sll = EulerMethod(0, 0 ,0.025 , 1.3999);
		cout << "sll " << sll << endl;

		cout <<"q "<< quocient(s, sl, sll)<< endl;
		cout <<"e "<< eulerError(sll, sl)<< endl;

		break;
	}
	/*case 2:
	{
		double a;
		cout << "Enter value to start:" << endl;
		cin >> a;

		cout << setprecision(3) << NewtonMethod(a, e);

	}*/
	case 2:
	{
		s = Rk2(0, 0, 0.1, 1.3999);
		cout << "s " << s << endl;

		sl = Rk2(0, 0, 0.05, 1.3999);
		cout << "sl " << sl << endl;

		sll = Rk2(0, 0, 0.025, 1.3999);
		cout << "sll " << sll << endl;

		cout << "q " << quocient(s, sl, sll) << endl;
		cout << "e " << Rk2error(sll, sl) << endl;
		break;
	}
	case 3:
	{
		s = Rk4(0, 0, 0.1, 1.3999);
		cout << "s " <<setprecision(8) <<  s << endl;

		sl = Rk4(0, 0, 0.05, 1.3999);
		cout << "sl " << sl << endl;

		sll = Rk4(0, 0, 0.025, 1.3999);
		cout << "sll " << sll << endl;

		cout << "q " << quocient(s, sl, sll) << endl;
		cout << "e " << Rk4error(sll, sl) << endl;

		break;
	}
	default:
	{
		cout << "error" << endl;
		break;
	}

	}
	return 0;
}

