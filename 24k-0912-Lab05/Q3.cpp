#include <vector>
#include <iostream>
using namespace std;

bool isSafe(vector<vector<bool>> &visited, int i, int j, vector<vector<int>> &input, int n)
{

   if ((i >= 0 && i <= n - 1) && (j >= 0 && j <= n - 1) && input[i][j] == 1 && visited[i][j] == false)
   {
      return true;
   }
   return false;
}

void path(int i, int j, vector<vector<int>> &input, vector<vector<int>> &ans, vector<vector<bool>> &visited, int n)
{
   if (i == n - 1 && j == n - 1 && input[i][j] == 1)
   {
      ans[i][j] = 1;

      return;
   }

   visited[i][j] = true;

   int newi = i + 1, newj = j;
   if (isSafe(visited, newi, newj, input, n))
   {
      ans[newi][newj] = 1;
      path(newi, newj, input, ans, visited, n);
   }

   newi = i - 1, newj = j;
   if (isSafe(visited, newi, newj, input, n))
   {
      ans[newi][newj] = 1;
      path(newi, newj, input, ans, visited, n);
   }

   newi = i, newj = j + 1;
   if (isSafe(visited, newi, newj, input, n))
   {
      ans[newi][newj] = 1;
      path(newi, newj, input, ans, visited, n);
   }

   newi = i, newj = j - 1;
   if (isSafe(visited, newi, newj, input, n))
   {
      ans[newi][newj] = 1;
      path(newi, newj, input, ans, visited, n);
   }

   visited[newi][newj] = false;
}

void solve()
{

   vector<vector<int>> input(7, (vector<int>(7, 0)));
   vector<vector<int>> ans(7, vector<int>(7, 0));

   cout << "Input Array: " << endl;

   for (int i = 0; i < 7; ++i)
   {

      for (int j = 0; j < 7; ++j)
      {
         cin >> input[i][j];
      }
   }

   vector<vector<bool>> visited(7, vector<bool>(7, false));

   if (input[0][0] == 0)
   {
      cout << "Path Can not be Found! " << endl;
   }
   else
   {

      int i = 0, j = 0;
      path(i, j, input, ans, visited, 7);

      cout << endl
           << endl;

      ans[0][0] = 1;

      for (const auto &row : ans)
      {
         for (int val : row)
         {
            cout << val << " ";
         }
         cout << std::endl;
      }
   }
}

int main()
{
   int t, i = 1;
   cout << "Enter the Test Cases: " << endl;
   cin >> t;
   while (t--)
   {
      cout << "Case #" << i << endl;
      solve();
      ++i;
   }
   return 0;
}