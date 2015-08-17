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
#include <vector>

#pragma warning(disable: 4018)

enum error
{
	A0, A1, A2, A3, A4
};

class matrix
{
private:
	int amount;
	int size;
	int zeroPoint;
	std::string row;
public:
	void matrixSet(int, int, std::string);
	void getValues(int&, int&, std::string&);
	void getValues(int&, int&, int&, std::string&);
	bool checckInput();
};

bool matrix::checckInput()
{
	/*+==================================================
	Checks that the string 'row' are all valid integers/floats/doubles.
	Example string for setup: 2 variables, 2 eqn.
	4,2,3;6,-1,-4;
	an equivalent set of solutions would be:
		{4x +  2y	=	 3
		{6x + -1y	=	-4
	==================================================+*/
	std::string allowed = "1234567890+-.eE";
	std::string segment = ";,";
	for (unsigned int i = 0; i < row.length(); i++)
	{
		
	}
}

void matrix::matrixSet(int noEqn, int noVar, std::string input)
{
	amount = noVar;
	size = noEqn;
	row = input;
}

void matrix::getValues(int &noEqn, int &noVar, std::string &input)
{
	noEqn = amount;
	noVar = size;
	input = row;
}

void matrix::getValues(int &noEqn, int &noVar, int &zero, std::string &input)
{
	noEqn = amount;
	noVar = size;
	input = row;
	zero = zeroPoint;
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

void integer(std::string input)
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
			error(A0, input);
		}
	}
	return;
}

void getInput(const int noEqn, const int noVar)
{
	std::vector<matrix*> equation;
	for (unsigned int i = 1; i <= noEqn; i++)//cycles through each equation
	{
		matrix *row;
		std::string buffer;
		std::string input;
		for (unsigned int j = 1; j <= noVar; j++)
		{
			std::cout << "Please enter variable " << j << ".\n>";
			std::cin >> buffer;
			input += (buffer + ",");//adds a comma to comma seperate the values
			if (j == noVar)//asks for answer on last pass
			{
				std::cout << "Please enter the solution to equation " << i << ".\n>";
				std::cin >> buffer;
				input += (buffer + ";");//done so the input doesn't get overwritten by cin., also adds a semicolon to show the end of a matrix.
			}
		}
		row = new matrix;
		row->matrixSet(noVar, noEqn, input);
		equation.push_back(row);
		delete row;//stop memory leaks or smth?
	}
}

void findOrSetOne(const int noEqn, const int noVar)
{
	std::vector<matrix> equation();
	for (unsigned int i = 1; i <= noEqn; i ++)
	{
		int noEqn = 0;
		int noVar = 0;
		std::string input;
		matrix temp = equation[i];
		equation(i).getValues(noEqn, noVar, input);

		//processInput

		for (unsigned int j = 1; j <= ((noEqn*noVar) + noEqn); j += (noVar + 1))//(noEqn*noVar) + noEqn //noEqn is there to add another column for the answers.
		{
			
		}
	}
}

int main()
{
	std::string input;

	std::cout << "How many equations?\n>";
	std::cin >> input;
	integer(input);
	const int noEqn = (int)atoi(input.c_str());

	std::cout << "How many variables?\n>";
	std::cin >> input;
	integer(input);
	const int noVar = (int)atoi(input.c_str());

	getInput(noEqn, noVar);
	findOrSetOne(noEqn, noVar);
	
	return 0;
}