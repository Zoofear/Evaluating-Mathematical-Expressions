#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include "Infix2Postfix.h"

//Functions

int Infix2Postfix::magnitudeChecker(std::string x)
{

	if (x == "^")
	{
		return 3;
	}
	else if (x == "/" || x == "*")
	{
		return 2;
	}

	else if (x == "+" || x == "-")
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int Infix2Postfix::operatorChecker(std::string token)
{

	if (token == "^" || token == "+" || token == "-" || token == "*" || token == "/" || token == "(" || token == ")")
	{
		return 1;
	}
	else if (std::isdigit(token[0]) || ((token[0] == '.' && token.length() > 1)) || ((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int Infix2Postfix::inputVerifyer(const std::string start)			//Evil Spaghetti Code
{
	if (start == " ")
	{
		std::cout << "Empty Input\n";
		return 0;
	}
	else if (inputSize() > 20)											//Makes sure the stack wont overflow from too many tokens in the expression
	{
		std::cout << "Stack Overflow! Over 20 operators and operands in the input\n";

		return 0;
	}
	else if (tokenVerifyer() == 0)
	{
		return 0;
	}
	
	std::istringstream ss(start);
	int j = 0;														//cursor for where to look within the stack
	int parenthesis1 = 0;											//counter for the amount of ( in the input
	int parenthesis2 = 0;											//counter for the amount of ) in the input*

	while (ss >> token)
	{	
		std::istringstream tss(start);								//Temporary istringstream function so that it can function separately within each iteration of ss
		std::string temp;											//Temporary string for TSS tokenizer
		while (tss >> temp)
		{
			temporarystack.push(temp);								//Tokenizer
		}
		std::string prev = " ";										//Variable to use to check what is the next token in the stack
		std::string next = " ";										//Variable to use to check what is the previous token in the stack
		if (operatorChecker(token) == 0)
		{

			if (j == 0)																	////This checks to see if the token being evaluated is at the start of the string, if it is then it needs a filler to make sure there isnt a false positive, since blank space gives no value on operatorChecker();
			{
				prev = "-";
			}
			else
			{
				while (temporarystack.size() != (j - 1) && !temporarystack.empty())		//This checks what the previous token in the expression is
				{
					prev = temporarystack.top();
					temporarystack.pop();
				}
				
				stackClearer();														//Cleans up stack to not cause issues
				
				std::istringstream tss(start);											//Fresh stack to evaluate
				while (tss >> temp)
				{
					temporarystack.push(temp);
				}
			}	

			if (j + 1 == temporarystack.size())										//This checks to see if the token being evaluated is at the end of the string, if it is then it needs a filler to make sure there isnt a false positive, since blank space gives no value on operatorChecker();
			{
				next = "-";
			}
			else
			{
				while (temporarystack.size() != (j + 1) && !temporarystack.empty())	//Iterating through the stack to find the token to be evaulated
				{
					next = temporarystack.top();
					temporarystack.pop();
				}
				stackClearer();
			}

			stackClearer();

			if ((operatorChecker(prev) != 1 || operatorChecker(next) != 1))//Evaluates the tokens to see if it needs to throw an error code
			{
				std::cout << "Operand Error\n";
				return 0;
			}

		}
		else if (operatorChecker(token) == 1 && token != "(" && token != ")" && !temporarystack.empty())	//This is for evaluating the operands specifically
		{
			while (temporarystack.size() != (j - 1) && !temporarystack.empty())		//This checks what the previous token in the expression is
			{
				prev = temporarystack.top();
				temporarystack.pop();
			}
			stackClearer();															//Cleans up stack to not cause issues

			std::istringstream tss(start);											//Fresh stack to evaluate
			while (tss >> temp)
			{
				temporarystack.push(temp);
			}
			if (temporarystack.size() == j + 1)										//If an operator is the last thing in an equation, the equation is not complete
			{
				stackClearer();														//Cleans the stack for the next run

				std::cout << "Operator Error\n";									//Error message
				
				return 0;
			}
			else																	//Checks to see if the next token in the expression is viable with the operator
			{
				while (temporarystack.size() != (j + 1) && !temporarystack.empty())	//Iterating through the stack to find the token to be evaulated
				{
						next = temporarystack.top();
						temporarystack.pop();
				}
			}
			stackClearer();															//Cleans the stack for the next run

			if ((operatorChecker(prev) != 0 || operatorChecker(next) != 0) && (next != "(" && prev != ")"))	//Evaluates the tokens to see if it needs to throw an error code
			{
				std::cout << "Operator Error\n";
				return 0;
			}
		}
		else if (token == "(")														//Checks for the parenthesis (
		{
			parenthesis1++;
			if (temporarystack.size() == j + 1)										//If an operator is the last thing in an equation, the equation is not complete
			{
				stackClearer();														//Cleans the stack for the next run

				std::cout << "Parenthesis ( Error\n";									//Error message

				return 0;
			}
			else																	//Checks to see if the next token in the expression is viable with the operator
			{
				while (temporarystack.size() != (j + 1) && !temporarystack.empty())	//Iterating through the stack to find the token to be evaulated
				{
					next = temporarystack.top();
					temporarystack.pop();
				}

				stackClearer();

				std::istringstream tss(start);											//Fresh stack to evaluate
				while (tss >> temp)
				{
					temporarystack.push(temp);
				}

				while (temporarystack.size() != (j - 1) && !temporarystack.empty())		//This checks what the previous token in the expression is
				{
					prev = temporarystack.top();
					temporarystack.pop();
				}
				stackClearer();															//Cleans up stack to not cause issues

			}
			stackClearer();

			if (prev == ")" || operatorChecker(prev) == 0)
			{
				std::cout << "Parenthesis ( Error\n";								//Error message

				return 0;
			}
		}
		else if (token == ")" )														//Checks for the parenthesis )
			{
				parenthesis2++;
			}
		
		j++;								//Iterator for the cursor of ss
	
	}
	
	stackClearer();											//Cleans the stack for the next run

	if ((parenthesis1 - parenthesis2) != 0)					//Makes sure that every parenthesis has a pair
	{
		std::cout << "Parenthesis Mismatch\n";

		return 0;
	}
	else													//Returns a 1 to tell the program it is good to go with the input
	{
		return 1;
	}
	
}

void Infix2Postfix::infixConverter()
{
	if (inputVerifyer(start) == 0)							//Check to make sure input is usable
	{
		output = "Error";									//Updates the output so no bad data is used on accident
	}
	else
	{
		std::istringstream ss(start);

		while (ss >> token)									//Tokenizer
		{
			std::string temp = "";							//Temporary function for adding from the stack
			int isoperator = operatorChecker(token);		//Function that checks whether or not the token is an operator
			if (isoperator == 1)							
			{
				if (token == "(")							//for parenthesis
				{
					temporarystack.push(token);				//Put onto the stack since it has the highest magnitude and is supposed to be the begginning of an enclosure for terms
				}
				else if (token == ")")
				{
					while (temporarystack.top() != "(" && (!temporarystack.empty()))	//Parses through the stack until it is either empty (to prevent a memory address issue) or it finds it other half (
					{
						temp = temporarystack.top();			//Printing from the stack since everything on here is the contents of the enclosure the other parenthesis created
						output += temp;
						output += " ";
						temporarystack.pop();
					}
					if (temporarystack.top() == "(")
					{
						temporarystack.pop();					//Pops the parenthesis to prevent it from being doubled
					}
				}
				else if (temporarystack.empty())
				{
					temporarystack.push(token);					//if the stack is empty it should push whatever operator comes next into the string so it can be saved and evaluated
				}
				else
				{
					if (magnitudeChecker(token) > magnitudeChecker(temporarystack.top()))	//compares the magnitude of the operator in the stack and the current token operator
					{
						temporarystack.push(token);											//If the token is more important and comes first it will be added to the stack so it will come out before the lesser operator
					}
					else if (magnitudeChecker(token) == magnitudeChecker(temporarystack.top()) && token == "^")
					{
						temporarystack.push(token);											//If both tokens are equal the only order that matters is the order they came in
					}
					else
					{
						while (!temporarystack.empty() && magnitudeChecker(token) <= magnitudeChecker(temporarystack.top()))	//If the token is smaller than the operator in the stack, the operators need to come out first, alongside any operands that come with them
						{
							temp = temporarystack.top();
							output += temp;
							output += " ";
							temporarystack.pop();
						}
						temporarystack.push(token);																	//Places the token  on the stack so it can be evaluated next
					}
				}
			}
			else if (isoperator == 0)
			{
				output += token;		//if it is an operand it can be directly added to the output
			}
		}
		while (!temporarystack.empty())	//printing the rest of the leftovers in the stack
		{
			output += temporarystack.top();
			output += " ";
			temporarystack.pop();
		}
	}
}