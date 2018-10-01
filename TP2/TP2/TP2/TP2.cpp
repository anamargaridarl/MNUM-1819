// TP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "math.h"

using namespace std;

double function(double x)
{
	return x - x * x;
}

double diff(double x)
{
	return 1 -2*x;
}

double NewtonMethod(double a, double b, int e)
{
	float x;
	
	while( )
}

double BissectionMethod(double a, double b, double e) // Used criteria n.1 
{
	/*
	Criterios para parar as iterações:

	1. Abs( a - b) < E        , E sendo um valor atribuido;
	2. n >= NR                , NR sendo um numero de valores atribuido
	3. abs( f(x) )  < E       , E sendo um valor atribuido --> este critério é menos rigoroso para muitas funções
	
	*/

	float x;
	int step = 0;

	x = (a + b) / 2;
	cout << setprecision(3) << x << endl;

	while (abs(b-a) >= e)
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

		cout << setprecision(3) << x << endl;
		step++;

	}
	
	cout << step << endl;
	return x;

}

int main()
{
	int flag = 0;
	
	cout << "1. Bissection Method" << endl;
	cout << "Choose Method: " << endl;
	cin >> flag;

	switch (flag)
	{
	case 1:
	{
		double a, b;
		double const e = 0.001;
		cout << "Enter the interval of function" << endl;
		cin >> a;
		cin >> b;
		
		cout << BissectionMethod(a, b, e) << endl;
	}
	case 2:
	{

	}
	}

	return 0;
}

