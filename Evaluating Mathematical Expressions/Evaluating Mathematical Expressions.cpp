// Evaluating Mathematical Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <stack>
#include "Infix2Postfix.h"

int main()
{
    std::string x = " ( A + -B * C ) / ( D - E ) ";

    Infix2Postfix expression(x);

   std::string y = expression.retrieveInput();

   std::cout << x << '\n';

   expression.infixConverter();

   std::cout << expression.returnOutput() << "\n";

   std::cout << '\n';

   x = " ( A + B * ( C - D ) ) / E ";

   Infix2Postfix expression1(x);

   std::cout << x << '\n';

   expression1.infixConverter();

   std::cout << expression1.returnOutput() << "\n";

   std::cout << '\n';

   x = " ";

   Infix2Postfix expression2(x);

   std::cout << x << '\n';

   expression2.infixConverter();

   std::cout << expression2.returnOutput() << "\n";

   std::cout << '\n';

   x = "A + B ) * C ";

   Infix2Postfix expression3(x);

   std::cout << x << '\n';
  
   expression3.infixConverter();

   std::cout << expression3.returnOutput() << "\n";

   std::cout << '\n';

   x = " ( A + B * C ";

   Infix2Postfix expression4(x);

   std::cout << x << '\n';
  
   expression4.infixConverter();

   std::cout << expression4.returnOutput() << "\n";

   std::cout << '\n';

   x = " A + B @ C ";

   Infix2Postfix expression5(x);

   std::cout << x << '\n';
   
   expression5.infixConverter();

   std::cout << expression5.returnOutput() << "\n";

   std::cout << '\n';

   x = " A + * B ";

   Infix2Postfix expression6(x);

   std::cout << x << '\n';
   
   expression6.infixConverter();

   std::cout << expression6.returnOutput() << "\n";

   std::cout << '\n';

   x = " A B + C ";

   Infix2Postfix expression7(x);

   std::cout << x << '\n';
  
   expression7.infixConverter();

   std::cout << expression7.returnOutput() << "\n";

   std::cout << '\n';

   x = " A + G ) B * C ( D + E ";

   Infix2Postfix expression8(x);

   std::cout << x << '\n';
   
   expression8.infixConverter();

   std::cout << expression8.returnOutput() << "\n";

   std::cout << '\n';

   x = " ( ( ( ( ( ( ( ( ( A + B ) ) ) ) ) ) ) ) ) ";

   Infix2Postfix expression9(x);

   std::cout << x << '\n';

   expression9.infixConverter();

   std::cout << expression9.returnOutput() << "\n";

   std::cout << '\n';

 
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
