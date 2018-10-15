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
	/*case 3:
	{
		SolveSystem3(4, 4, e2);
		break;
	}
	*/
	default:
		cout << "Error" << endl;
		break;
	}

	return 0;
}

