// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip> 

using namespace std;

void srIngenuo()
{
	double value;
	value = exp(1.0) - 1;

	for (int i = 1; i < 26; i++)
	{
		value = value * i - 1;
		cout << i << "   " << setprecision(12) << value << endl;
	}
}

int main()
{

	srIngenuo();

	return 0;
}

