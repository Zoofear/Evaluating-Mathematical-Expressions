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

	void tokenizer();		//tokenizes the input to allow it to be evaluated by each element individually and manipulated individually

	int operatorChecker(std::string token);							//checks whether or not the token is an operator or operand 

	void infixConverter();	//takes the temporary stack and adds it to the ouput stack#pragma

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

	void printtempstack()
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