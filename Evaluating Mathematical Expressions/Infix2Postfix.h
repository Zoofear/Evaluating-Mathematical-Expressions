#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>


class Infix2Postfix
{
public:

	Infix2Postfix(const std::string& input)								//you need the input string to evaluate, and then the address of a stack that you want to put the postfix equation in
	{
		setInput(input);
	};

	/*void tokenizer();		//tokenizes the input to allow it to be evaluated by each element individually and manipulated individually*/

	int operatorChecker(std::string token);	//checks whether or not the token is an operator or operand

	int magnitudeChecker(std::string x);    // checks the magnitude of the operator to order the operators

	int inputVerifyer(const std::string start);					//verifys the input to make sure it is usable

	void infixConverter();	//takes the temporary stack and adds it to the ouput stack

	void stackClearer()		//clears temporarystack

	{
		while (!temporarystack.empty())
		{
			temporarystack.pop();
		}
	}

	int inputSize()
	{	
		std::istringstream tss(start);
		std::string temp;
		int k = 0;						//Starts at 1 because im counting the iterations, not using it as a cursor
		while (tss >> temp)
		{
			k++;
		}

		return k;
	}

	int tokenVerifyer()
	{
		std::istringstream ss(start);
		while (ss >> token)
		{
			if (operatorChecker(token) == -1)							//Checks to see if there is an invalid operator or operand and doesnt allow it to be used
			{
				stackClearer();											//Cleans the stack for the next run

				std::cout << "Error with this token: " << token << "\n";//error message
				return 0;												//error output
			}
		}
		
		return 1;
	}

	void setInput(const std::string input)
	{
		start = input;
	}

	std::string retrieveInput()
	{
		return start;
	}

	std::string returnOutput()
	{
		return output;
	}

	void printtempstack()	//Test program to make sure the stack is empty 
	{
		if (temporarystack.empty())
		{
			std::cout << "erm im an empty stack\n";
		}

		while (!temporarystack.empty())
		{
			std::cout << temporarystack.top();
			temporarystack.pop();
		}
	}

private:
	std::string start;
	std::string output;
	std::stack<std::string> temporarystack;		//temporary stack for holding operators and operands when converting to postfix											//string to hold each token being evaluated by
	std::string token;

	
};