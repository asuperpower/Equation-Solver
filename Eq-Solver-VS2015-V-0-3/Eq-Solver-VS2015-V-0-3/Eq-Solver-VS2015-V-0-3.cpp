/*+==================================================
Title:      Equation Solver
Version:    V0.4
Changes:	Since V0.0.3:
			Changed the command argument input metho-
			d to using CIN
			Since V0.0.2:
			Using classes for matrix operations
Author:     Anthony Ashton
Date:       13/08/2015
Aim:        To solve simulataneous equations using g-
aussian elimination and classes.
==================================================+*/
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <cmath>

enum error
{
	A0, A1, A2, A3, A4
};

class matrix
{
private:
	int size;
	int start;
	int zeroPoint;
public:
	void matrixSet(int, int, int);
	void input()
};

void matrix::matrixSet(int length, int begin, int zero)
{
	size = length;
	start = begin;
	zeroPoint = zero;
}

void matrix::input()
{

}

void error(int code, std::string input)
{
	switch (code)
	case A0:
	{
		std::cout << "Input: '" << input.c_str() << "' wasn't an integer!";
		exit(0xA0);
	}	
}

bool integer(std::string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		std::string allowed = "1234567890";
		bool match = false;
		for (unsigned int j = 0; j < allowed.length(); j++)
		{
			if (input[i] == allowed[j])
			{
				match = true;
			}
		}
		if (!match)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string input;

	std::cout << "\nHow many equations\n";
	std::cin >> input;
	if (!integer(input))
	{
		error(A0, input);
		exit(A0);
	}
	const int noEqn = (int)atoi(input.c_str());

	std::cout << "\nHow many variables?\n";
	std::cin >> input;
	if (!integer(input))
	{
		error(A0, input);
		exit(A0);
	}
	const int noVar = (int)atoi(input.c_str());

	//need to put this in a method for matrix class and then this is repeated for each row.
	for (unsigned int i = 1; i <= noVar; i++)
	{
		std::cout << "\nVariable " << i + 1 << ": \n";
		std::cin >> input;
	}

	return 0;
}