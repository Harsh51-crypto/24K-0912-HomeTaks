#include <vector>
#include <iostream>
using namespace std;

int sum(int n)
{
   if (n == 0)
   {
      return n;
   }

   return n % 10 + sum(n / 10);
}

int singleDigit(int n)
{

   int ans = sum(n);
   if (ans >= 0 && ans < 10)
   {
      return ans;
   }

   n = ans;
   return singleDigit(n);
}

int main()
{
   int n;
   cout << "Enter the Number: " << endl;
   cin >> n;

   cout << singleDigit(n) << " ";

       return 0;
}