#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> &a)
{
   int m = a[0];
   for (int x : a)
      if (x > m)
         m = x;
   return m;
}

void countSort(vector<int> &a, int exp)
{
   int n = a.size();
   vector<int> output(n);
   int count[10] = {0};
   for (int i = 0; i < n; i++)
      count[(a[i] / exp) % 10]++;
   for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];
   for (int i = n - 1; i >= 0; i--)
   {
      output[count[(a[i] / exp) % 10] - 1] = a[i];
      count[(a[i] / exp) % 10]--;
   }
   a = output;
}

void radixSort(vector<int> &a)
{
   int m = getMax(a);
   for (int exp = 1; m / exp > 0; exp *= 10)
      countSort(a, exp);
}

int main()
{
   vector<int> ids = {54321, 12345, 67890, 23456, 34567, 98765, 87654, 76543, 65432, 45678,
                      11223, 22334, 33445, 44556, 55667, 66778, 77889, 88990, 99001, 10112};
   cout << "Before Sorting:\n";
   for (int x : ids)
      cout << x << " ";
   cout << "\n\nAfter Sorting:\n";
   radixSort(ids);
   for (int x : ids)
      cout << x << " ";
}
