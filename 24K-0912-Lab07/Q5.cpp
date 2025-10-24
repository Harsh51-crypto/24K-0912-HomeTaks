#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int comparisons = 0;

int partition(vector<int> &a, int low, int high, int pivotIndex)
{
   swap(a[pivotIndex], a[high]);
   int pivot = a[high];
   int i = low - 1;
   for (int j = low; j < high; j++)
   {
      comparisons++;
      if (a[j] < pivot)
         swap(a[++i], a[j]);
   }
   swap(a[i + 1], a[high]);
   return i + 1;
}

void quickSort(vector<int> &a, int low, int high, string method)
{
   if (low < high)
   {
      int pivotIndex;
      if (method == "first")
         pivotIndex = low;
      else if (method == "random")
         pivotIndex = low + rand() % (high - low + 1);
      else if (method == "middle")
         pivotIndex = (low + high) / 2;
      else
      {
         int mid = (low + high) / 2;
         vector<int> temp = {a[low], a[mid], a[high]};
         sort(temp.begin(), temp.end());
         int median = temp[1];
         if (median == a[low])
            pivotIndex = low;
         else if (median == a[mid])
            pivotIndex = mid;
         else
            pivotIndex = high;
      }

      int pi = partition(a, low, high, pivotIndex);
      quickSort(a, low, pi - 1, method);
      quickSort(a, pi + 1, high, method);
   }
}

int main()
{
   srand(time(0));
   vector<int> data = {10, 7, 8, 9, 1, 5, 3};
   vector<string> methods = {"first", "random", "middle", "median"};
   for (auto &m : methods)
   {
      vector<int> arr = data;
      comparisons = 0;
      quickSort(arr, 0, arr.size() - 1, m);
      cout << m << " pivot: ";
      for (int x : arr)
         cout << x << " ";
      cout << " | comparisons: " << comparisons << endl;
   }
}
