// TP4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>

using namespace std;

double function(double x) 
{
	return sin(x) /(x * x);
}

double functionC(double x, double y)
{
	return exp(y - x);
}

double hfunction(double a, double b, double n)
{
	return (b - a) / n;
}

double hlinha(double h)
{
	return h / 2;
}

double Qct(double s, double sl, double sll)
{
	double result;

	result = (sl -s)/(sll-sl);
	return result;
}

///////////////////////////////////
////   Trapezio Method ////////////
//////////////////////////////////
double STrapezioMethod(double a, double b,int n)
{
	double result, h;
	h = hfunction(a, b, n);
	
	result = function(a) + function(b);

	 
	// 2*f(a+i*h)
	for (int i = 1; i < n; i++)
	{
		result = result + 2 * function(a + i*h);
	}
	result = (h / 2)* result;

	return result;
}

double ETrapezio(double Sll, double Sl)
{
	
	return (Sll - Sl) / 3;

}
///////////////////////////////////
////    Simpson Method ////////////
//////////////////////////////////
double ESimpson(double Sll, double Sl)
{
	return (Sll - Sl) / 15;
}


double SimpsonMethod(double a, double b, int n)
{
	if (n % 2 != 0)
	{
		cout << "N needs to be even" << endl;
		return -1;
	}

	double result, h;
	h = hfunction(a, b, n);

	result = function(a) + function(b);

	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 0)
			result = result + 2 * function(a + i * h);
		else
			result = result + 4 * function(a + i * h);

	}
	result = (h / 3)* result;

	return result;


}

////////////////////////
////  Cubatura ////////
//////////////////////

double Sum1(double xo, double xf, double yo, double yf, double hx, double hy)
{
	double s1 = 0;
	
	s1 = functionC(xo + hx, yo) + functionC(xo, yo + hy) + functionC(xo + 2 * hx, yo + hy) + functionC(xo + hx, yo + 2 * hy);

	return s1;
}

double Sum2(double xo, double xf, double yo, double yf,double hx, double hy)
{
	return functionC(xo +hx,yo + hy);
}

double CubaturaTrapezio(double xo, double xf, double yo, double yf, double nx, double ny)
{
	double Sum0, hx, hy, result;

	hx = (xf - xo) / nx;
	hy = (yf - yo) / ny;

	Sum0 = functionC(xo, yo) + functionC(xf, yf) + functionC(xf, yo) + functionC(xo, yf);

	result = Sum0 + 2*Sum1(xo, xf, yo, yf,hx,hy) + 4*Sum2(xo, xf, yo, yf,hx,hy);

	result = result * ((hx*hy) / 4);

	return result;

}

double CubaturaSimpson(double xo, double xf, double yo, double yf, double nx, double ny)
{
	double  hx, hy;
	double xfi, yfi, soma;
	double xi, yi;
	double nmalhasx, nmalhasy;

	hx = (xf - xo) / nx;
	hy = (yf - yo) / ny;
	
	if (((int)nx % 2 != 0) || ((int)ny % 2 != 0))
	{
		cout << "not even" << endl;
		exit(1);
	}

	nmalhasx = nx / 2;
	nmalhasy = ny / 2;
	
	y
	
	return soma;

}

int main()
{
	int flag = 0;
	double pi = acos(-1);

	cout << "1.Trapezio" << endl;
	cout << "2.Simpson" << endl;
	cout << "3.Cubatura" << endl;

	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		double S, Sl, Sll;
		double a, b;
		int n;

		/*
		cout << "a,b,n" << endl;
		cin >> a;
		cin >> b;
		cin >> n;
		*/

		b = pi;
		a = pi / 2;
		n = 4;

		S = STrapezioMethod(a, b, n);
		cout << "S: " << S << endl;
		Sl = STrapezioMethod(a, b, 2*n);
		cout << "Sl: " << Sl << endl;
		Sll = STrapezioMethod(a, b, 2*(2*n));
		cout << "Sll: " << Sll << endl;

		cout << "Qct: " << Qct(S, Sl, Sll) << endl;

		cout << "Error: "<< ETrapezio(Sll, Sl) << endl;

		break;
	}
	case 2:
	{
		double S, Sl, Sll;
		double a, b;
		int n;

		/*
		cout << "a,b,n" << endl;
		cin >> a;
		cin >> b;
		cin >> n;
		*/

		b = pi;
		a = pi / 2;
		n = 4;

		S = SimpsonMethod(a, b, n);
		cout << "S: " << S << endl;
		Sl = SimpsonMethod(a, b, 2 * n);
		cout << "Sl: " << Sl << endl;
		Sll = SimpsonMethod(a, b, 2 * (2 * n));
		cout << "Sll: " << Sll << endl;

		cout << "Qct: " << Qct(S, Sl, Sll) << endl;

		cout << "Error: " << ESimpson(Sll, Sl) << endl;

		break;
	}
	case 3:
	{
		int flag = 0;
		cout << "1.Trapezio 2.Simpson " << endl;
		cin >> flag;
		if (flag == 1)
			cout << CubaturaTrapezio(0, 0.5, 0, 0.5, 2, 2);
		else if (flag == 2)
			cout << CubaturaSimpson(0, 0.5, 0, 0.5, 2, 2);
		else
		{
			cout << "error" << endl;
			exit(1);
		}

		break;
	}
	default:
		cout << "Error" << endl;
		break;
	}

	return 0;
}

