#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
   string exp;
   cout << "Enter Postfix Expression: ";
   cin >> exp;
   stack<int> s;
   for (char ch : exp)
   {
      if (isdigit(ch))
         s.push(ch - '0');
      else
      {
         int b = s.top();
         s.pop();
         int a = s.top();
         s.pop();
         switch (ch)
         {
         case '+':
            s.push(a + b);
            break;
         case '-':
            s.push(a - b);
            break;
         case '*':
            s.push(a * b);
            break;
         case '/':
            s.push(a / b);
            break;
         case '^':
            s.push(pow(a, b));
            break;
         }
      }
   }
   cout << "Result: " << s.top();
}
