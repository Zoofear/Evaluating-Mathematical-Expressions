#pragma once

#include "PostfixEval.h"

int PostfixEval::operatorChooser(char z)	//just gives an int for whatever operator is used
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
	std::istringstream ss(input);
	if (!ss)
	{
		std::cout << "Your input is empty!\n";
		return;
	}
	while (ss >> token)
	{
			if (std::isdigit(token[0]) || ((token[0] == '-' || token[0] == '.') && token.length() > 1))				//checks if the token is a number
			{
				double number = std::stod(token);
				operands.push(number);
			}
			else if (operatorChooser(token[0]) > 0 && operatorChooser(token[0]) < 6)		//checks if the token is an operator
			{
				double val1;														//temporary values to pop from stack to use when the token is an operand
				double val2;														//temporary values to pop from stack to use when the token is an operand
				
				if (!operands.empty())												//preventing the calling and popping of an empty stack
				{
					val2 = operands.top();
					operands.pop();
				}
				else
				{
					std::cout << "Trying to access an empty stack! Please check input\n";		//error message
					return;
				}
				if (!operands.empty())												//preventing the calling and popping of an empty stack
				{
					val1 = operands.top();
					operands.pop();
				}
				else
				{
					std::cout << "Trying to access an empty stack! Please check input\n";		//error message
					return;
				}
	
				if (operatorChooser(token[0]) == 5)
				{
					operands.push(exponent(val1, val2));
				}
				else if (operatorChooser(token[0]) == 4)
				{
					operands.push(multiplication(val1, val2));
				}
				else if (operatorChooser(token[0]) == 3)
				{
					operands.push(division(val1, val2));
				}
				else if (operatorChooser(token[0]) == 2)
				{
					operands.push(addition(val1, val2));
				}
				else if (operatorChooser(token[0]) == 1)
				{
					operands.push(subtraction(val1, val2));
				}
				else
				{
					std::cout << "something went wrong with the operator chooser function \n";	//error message, even though this should never occur since there is a check
					return;
				}
			}
			else
			{
				std::cout << "input error with: " << token << "\n";
				return;
			}
	}
	
	if (!operands.empty())
	{
		output = operands.top();
	}
	else if (operands.empty())
	{
		std::cout << "There is nothing to evaluate\n";
	}
	else if (operands.size() != 1)
	{
		std::cout << "There is an error with the output, as there are still operands in the stack\nStack: ";
		while (!operands.empty())
		{
			std::cout << operands.top() << " ";
			operands.pop();
		}
		output = 0;
		std::cout << "\n";
		return;
	}
	else
	{
		while (!operands.empty())
		{
			operands.pop();
		}
	}
	
}