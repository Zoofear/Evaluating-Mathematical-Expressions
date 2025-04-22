// Evaluating Mathematical Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Infix2Postfix.h"
#include "PostfixEval.h"

int main()
{
	std::ifstream file;
	file.open("RpnData.txt");

	if (!file.fail())
	{
		int j = 1;
		while (!file.eof())
		{
			std::cout << j << "\n";
			j++;

			std::string expression;
			getline(file, expression);

			PostfixEval testeval(expression);
			testeval.eval();

			double output = testeval.returnOutput();
			std::cout << "Postfix: " << expression << "\nEvaluated : " << output << "\n";
		}
	}
	else if (file.fail())
	{
		std::cout << "file error \n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
