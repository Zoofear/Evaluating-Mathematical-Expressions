#pragma once

#include "PostfixEval.h"

int PostfixEval::operatorChooser(char z)
{

	char c = z;

	if (c == '^')
	{
		return 5;
	}
	else if (c == '*')
	{
		return 4;
	}
	else if (c == '/')
	{
		return 3;
	}
	else if (c == '+')
	{
		return 2;
	}
	else if (c == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void PostfixEval::eval()
{

	{
			std::cout << token << "\n";
			if (std::isdigit(token[0]) || (token[0] == '.' && token.length() > 1))
			{
				double number = std::stod(token);
				operands.push(number);
			}
			else if (operatorChooser(token[0]) > 0 && operatorChooser(token[0]) < 6)
			{
				double val1 = operands.top();
				operands.pop();
				double val2 = operands.top();
				operands.pop();
	
				if (operatorChooser(token[0] == 5))
				{
					operands.push(exponent(val1, val2));
				}
				else if (operatorChooser(token[0] == 4))
				{
					operands.push(multiplication(val1, val2));
				}
				else if (operatorChooser(token[0] == 3))
				{
					operands.push(division(val1, val2));
				}
				else if (operatorChooser(token[0] == 2))
				{
					operands.push(addition(val1, val2));
				}
				else if (operatorChooser(token[0] == 1))
				{
					operands.push(subtraction(val1, val2));
				}
				else
				{
					std::cout << "something went wrong with the operator chooser function \n";
				}
			}
			else
			{
				std::cout << "input error with: " << token << "\n";
				return;
			}
	}

	output = operands.top();
}