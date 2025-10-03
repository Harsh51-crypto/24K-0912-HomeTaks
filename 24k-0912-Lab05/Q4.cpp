#include <vector>
#include <iostream>
using namespace std;

void copy(vector<vector<int>> &board, vector<vector<char>> &ans, int n)
{

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         if (board[i][j] == 1)
         {
            ans[i][j] = 'Q';
         }
         else
         {
            ans[i][j] = '.';
         }
      }
   }

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cout << ans[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl
        << endl;
}

bool isSafe(vector<vector<int>> &board, int n, int i, int j)
{

   int x = i, y = j;
   while (y >= 0)
   {
      if (board[x][y] == 1)
      {
         return false;
      }
      --y;
   }

   x = i, y = j;
   while (x >= 0 && y >= 0)
   {

      if (board[x][y] == 1)
      {
         return false;
      }
      --y;
      --x;
   }
   x = i, y = j;
   while (x < n && y >= 0)
   {
      if (board[x][y] == 1)
      {
         return false;
      }
      --y;
      ++x;
   }
   return true;
}
void solve(vector<vector<int>> &board, vector<vector<char>> &ans, int col, int n)
{

   if (col == n)
   {
      copy(board, ans, n);
      return;
   }

   for (int i = 0; i < n; ++i)
   {
      if (isSafe(board, n, i, col))
      {
         board[i][col] = 1;
         solve(board, ans, col + 1, n);
         board[i][col] = 0;
      }
   }
}

int main()
{

   int n;
   cout << "Enter the Size of Chess Board: " << endl;
   cin >> n;

   vector<vector<char>> ans(n, vector<char>(' ', n));
   vector<vector<int>> board(n, vector<int>(n, 0));

   int count = 0;

   solve(board, ans, 0, n);

   return 0;
}