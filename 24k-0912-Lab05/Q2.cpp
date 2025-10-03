
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &ans, int i, int j, vector<vector<int>> &input, int n)
{

   if (i <= n - 1 && j <= n - 1 && input[i][j] == 1)
   {

      return true;
   }
   return false;
}

bool path(int i, int j, vector<vector<int>> &input, vector<vector<int>> &ans, int n)
{

   if (i == n - 1 && j == n - 1 && input[i][j]==1)
   {
      ans[i][j]=1;
      return true;
   }
   

   if (isSafe(ans, i, j, input, n))
   {
      ans[i][j] = 1;
   

   if (path(i + 1, j, input, ans, n))
   {

      return true;
   }

   if (path(i, j + 1, input, ans, n))
   {
      return true;
   }
}

   ans[i][j] = 0;
   return false;
}
void solve()
{

   int n;
   cout << "Enter the Size of Sqaure Matrix: " << endl;
   cin >> n;

   vector<vector<int>> input(n, vector<int>(n, 0));
   ;
   vector<vector<int>> ans(n, vector<int>(n, 0));
   ;

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cin >> input[i][j];
      }
   }

   path(0, 0, input, ans, n);

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cout << ans[i][j] << " ";
      }
      cout << endl;
   }
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
