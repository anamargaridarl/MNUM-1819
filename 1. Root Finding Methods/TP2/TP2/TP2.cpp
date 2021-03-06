// TP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "math.h"

using namespace std;

/*
Calculates with different Methods:

-Bissection Method
-Regula Falsi/ Corte Method
-Picard Peano Method / iterativo simples
-Newton/Tangente Method 

*/

void Intro()
{
	cout << "-------------------------------------" << endl;
	cout << "Function x- x^2" << endl;
	cout << "Calculates with different Methods:" << endl;

	cout << "-Bissection Method" << endl;
	cout << "-Regula Falsi/ Corte Method" << endl;
	cout << "-Picard Peano Method / iterativo simples" << endl;
	cout<< "-Newton/Tangente Method" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "MENU" << endl;

}
double function(double x)
{
	return x - x * x;
}

double diff(double x)
{
	return 1 -2*x;
}

double F(double x)
{
	return x*x;
}

//esta a dar valores com precisao errada
double NewtonMethod(double a, double e)
{
double x;
int step = 1;

x = a - function(a) / diff(a);

cout << step << " ";
cout << setprecision(3) << x << endl;

while (abs(a - x) >= e)
{
	a = x;
	x = a - function(a) / diff(a);

	cout << step << " ";
	cout << setprecision(3) << x << endl;

	step++;
}

return x;
}

double BissectionMethod(double a, double b, double e) // Used criteria n.1 
{
	/*
	Criterios para parar as iterações:

	1. Abs( a - b) < E        , E sendo um valor atribuido;
	2. n >= NR                , NR sendo um numero de valores atribuido
	3. abs( f(x) )  < E       , E sendo um valor atribuido --> este critério é menos rigoroso para muitas funções

	*/

	double x;
	int step = 0;

	x = (a + b) / 2;

	cout << step << " ";
	cout << setprecision(3) << x << endl;

	while (abs(b - a) >= e)
	{
		if (function(a)*function(x) <= 0)
			// funtion(a) > 0 && function(x) < 0 || function(a) <=0 && function(x) >= 0
		{
			b = x;
		}
		else
		{
			a = x;
		}

		x = (a + b) / 2;

		cout << step << " ";
		cout << setprecision(3) << x << endl;
		step++;

	}

	cout << step << endl;
	return x;

}

//esta a dar valores com precisao errada
double RegulaFalsiMethod(double a, double b, double e)
{
	double x;
	int step = 0;

	x = (a * function(b) - b * function(a)) / (function(b) - function(a));

	cout << step << " ";
	cout << x << endl;

	while (abs(b - a) >= e)
	{
		if ((function(x)*function(a)) < 0)
		{
			b = x;
		}
		else
			a = x;

		x = (a * function(b) - b * function(a)) / (function(b) - function(a));

		cout << step << " ";
		cout << x << endl;
		step++;
	}

	return x;

}

//metodo de paragem:numero de iteraçoes
double PicardPeano(double a, double n)
{
	double x;
	int step = 0;
	x = F(a);

	while (step != n)
	{
		a = x;
		x = F(a);
		
		cout << x << endl;

		step++;
	}

	return x;
}

int main()
{
	Intro();

	int flag = 0;
	double const e = 0.001;
	
	cout << "1. Bissection Method" << endl;
	cout << "2. Newton Method" << endl;
	cout << "3. Regula-Falsi Method" << endl;
	cout << "4. Picard Peano Method" << endl;
	cout << "Choose Method: " << endl;
	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		double a, b;
		cout << "Enter the interval of function" << endl;
		cin >> a;
		cin >> b;

		cout << BissectionMethod(a, b, e) << endl;
	}
	case 2:
	{
		double a;
		cout << "Enter value to start:" << endl;
		cin >> a;

		cout << setprecision(3) << NewtonMethod(a, e);

	}
	case 3:
	{
		double a, b;
		cout << "Enter the interval of function" << endl;
		cin >> a;
		cin >> b;

		cout << RegulaFalsiMethod(a, b, e);
	}
	case 4:
	{
		double a;
		double const n = 20;
		cout << "Enter value to start:" << endl;
		cin >> a;

		cout << PicardPeano(a, n);

	}
	}
	return 0;
}

