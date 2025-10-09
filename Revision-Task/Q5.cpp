#include <iostream>
using namespace std;

void save(bool **visited, char **ans, int n, char obj)
{

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         if (visited[i][j] == true)
            ans[i][j] = obj;
         else
            ans[i][j] = '.';
      }
   }
}

bool isSafe(int **arr, int i, int j, bool **visited, int n, int rowstart, int colstart, int rowend, int colend)
{
   if (i >= rowstart && i < rowend && j >= colstart && j < colend && visited[i][j] == false && arr[i][j] == 1)
   {
      return true;
   }
   return false;
}

void path(int i, int j, int **arr, int n, bool **visited, char **ans, char obj, int rowstart, int colstart, int rowend, int colend)
{

   if (i == (n / 2) && j == (n / 2))
   {
      visited[i][j] = true;
      save(visited, ans, n, obj);
      visited[i][j] = false;
      return;
   }

   if (isSafe(arr, i, j, visited, n, rowstart, colstart, rowend, colend))
   {
      visited[i][j] = true;

      path(i + 1, j, arr, n, visited, ans, obj, rowstart, colstart, rowend, colend);
      path(i, j + 1, arr, n, visited, ans, obj, rowstart, colstart, rowend, colend);
      path(i - 1, j, arr, n, visited, ans, obj, rowstart, colstart, rowend, colend);
      path(i, j - 1, arr, n, visited, ans, obj, rowstart, colstart, rowend, colend);

      visited[i][j] = false;
   }
}
int main()
{

   int **arr, **intersect;
   int n;
   cin >> n;
   char **cat, **rabbit;
   arr = new int *[n];
   cat = new char *[n];
   intersect = new int *[n];
   rabbit = new char *[n];
   bool **visited;
   visited = new bool *[n];
   for (int i = 0; i < n; ++i)
   {
      arr[i] = new int[n];
      visited[i] = new bool[n];
      cat[i] = new char[n];
      rabbit[i] = new char[n];
      intersect[i] = new int[n];
   }

   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cin >> arr[i][j];
         visited[i][j] = false;
         intersect[i][j] = 0;

         rabbit[i][j] = '.';
         cat[i][j] = '.';
      }
   }

   path(0, 0, arr, n, visited, rabbit, 'R', 0, 0, n / 2 + 1, n / 2 + 1);
   path(n - 1, n - 1, arr, n, visited, cat, 'C', n / 2, n / 2, n, n);

   cout << endl
        << "Rabbit Path: " << endl;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cout << rabbit[i][j] << " ";
      }
      cout << endl;
   }

   cout << endl
        << "Cat Path: " << endl;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         cout << cat[i][j] << " ";
      }
      cout << endl;
   }

   bool found = false;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < n; ++j)
      {
         if (cat[i][j] == 'C' && rabbit[i][j] == 'R')
         {
            cout << "(" << i << "," << j << ")" << " ";
            found = true;
         }
      }
   }

   if (!found)
      cout << "No InterSection Points: " << endl;

   return 0;
}