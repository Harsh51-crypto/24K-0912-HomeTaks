#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
   if (c == '^')
      return 3;
   if (c == '*' || c == '/')
      return 2;
   if (c == '+' || c == '-')
      return 1;
   return -1;
}

int main()
{
   string exp = "a+b*(c^d-e)^(f+g*h)-i", res;
   stack<char> s;
   for (char c : exp)
   {
      if (isalnum(c))
         res += c;
      else if (c == '(')
         s.push(c);
      else if (c == ')')
      {
         while (!s.empty() && s.top() != '(')
         {
            res += s.top();
            s.pop();
         }
         s.pop();
      }
      else
      {
         while (!s.empty() && prec(s.top()) >= prec(c))
         {
            res += s.top();
            s.pop();
         }
         s.push(c);
      }
   }
   while (!s.empty())
   {
      res += s.top();
      s.pop();
   }
   cout << "Postfix: " << res;
}
