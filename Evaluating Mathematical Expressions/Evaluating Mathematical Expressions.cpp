// Evaluating Mathematical Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <stack>

int main()
{
        std::string input = "12 3.5 + 7 * 2 -";
        std::istringstream ss(input);
        std::string token;
        std::stack<std::string> postfix;
        while (std::getline(ss, token, ' ')) {
            postfix.push(token);
        }
        int total = postfix.size();
        for (int j = 0; j < total; j++)
        {
            std::cout << postfix.top();
            postfix.pop();
        }

        /*if (token == "+" || token == "-" || token == "/" || token == "*")
             {
                 int weight = 0;

                 if (token == "*" || token == "/")


                 if (token ==
                     )
                 {

                 }

             }
             else if (token == "("
             {

             }
             else if (token == ")")
             {

             }
             else
             {
                 postfix.push(token);
             }*/
  





        return 0;

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
