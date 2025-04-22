#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class PostfixEval
{
public:

	PostfixEval(std::string input);

	double exponent(double x, char z, double y);

	double multiplication(double x, char z, double y);

	double division(double x, char z, double y);

	double addition(double x, char z, double y);

	double subtraction(double x, char z, double y);

	int operatorChooser(char z);

	double eval();

	void setInput();

	void returnOutput();




private:
	std::string input;
	double output;
	std::stack<double> operand;
	std::stack<char> operators;
};