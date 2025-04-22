#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>

class PostfixEval
{
public:

	PostfixEval(std::string x)
	{
		setInput(x);
	}

	double exponent(double x,  double y)
	{
		return pow(x, y);
	}

	double multiplication(double x, double y)
	{
		return (x * y);
	}

	double division(double x, double y)
	{
		if (y == 0)
		{
			std::cout << "You're attempting to divide by 0\n";	//prevents division by 0
			return 0;
		}

		return (x / y);
	}

	double addition(double x, double y)
	{
		return (x + y);
	}

	double subtraction(double x, double y)
	{
		return (x - y);
	}

	int operatorChooser(char z);		//just gives an int for whatever operator is used

	void eval();						//reads the postfix string and evaluates it then sets output as the results

	void setInput(std::string x)
	{
		input = x;
	}

	double returnOutput()
	{
		return output;
	}




private:
	std::string input;
	double output;
	std::string token;
	std::stack<double> operands;
};