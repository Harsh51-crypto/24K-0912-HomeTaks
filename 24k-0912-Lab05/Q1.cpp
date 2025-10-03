
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guess(int n)
{

   cout << "Enter the Number:" << endl;
   int target;
   cin >> target;

   if (n == target)
   {
      cout << "Correct Guess: " << endl;
      return;
   }

   else if (target > n)
   {
      cout << "You Guessed High: " << endl;
      guess(n);
   }

   else
   {
      cout << "You Guessed low: " << endl;
      guess(n);
   }
}

void solve()
{

   srand(time(0));
   int n = rand() % 100 + 1;

   guess(n);
}
int main()
{

   int t, i = 0;
   cin >> t;

   while (t--)
   {
      cout << "Case # " << i + 1 << endl;
      solve();
      ++i;
   }
   return 0;
}
