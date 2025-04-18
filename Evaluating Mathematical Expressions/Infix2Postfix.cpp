#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include "Infix2Postfix.h"

//Functions

int operatorChecker(std::string token)
{
	if (token == "(" || token == ")")
	{
		return 3;
	}

	else if (token == "/" || token == "*")
	{
		return 2;
	}
	else if (token == "+" || token == "-")
	{
		return 1;
	}
	else if (std::isdigit(token[0]) || (token[0] == '.' && token.length() > 1))
	{
		return 0;
	}	
	else
	{
		std::cout << "An error with the token has occured, please check the input\n";
	}
}


void Infix2Postfix::infixConverter()
{
	std::istringstream ss(start);

	while (ss >> token)
	{
		int magnitude = operatorChecker(token);
		if (magnitude != 0)
		{
			if (magnitude == 3)
			{

			}
		}
		else if (magnitude == 0)
		{

			if (token == "")
			{
				;
			}
			else if
		}
	}
}

