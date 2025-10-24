#include <vector>
#include <iostream>
using namespace std;

class Person
{

public:
   string name;
   int racetime;

   Person()
   {
   }

   Person(string name, int sec) : name(name), racetime(sec) {}

   void setdata(string name, int time)
   {
      this->name = name;
      racetime = time;
   }
};

void mergesort(Person *p, int left, int right, int mid)
{
   int n = mid - left + 1, m = right - mid;

   Person *t1 = new Person[n], *t2 = new Person[m];

   for (int i = 0; i < n; ++i)
   {
      t1[i] = p[left + i];
   }
   for (int i = 0; i < m; ++i)
   {
      t2[i] = p[mid + 1 + i];
   }

   int i = 0, j = 0, k = left;

   while (i < n && j < m)
   {

      if (t1[i].racetime <
          t2[j].racetime)
      {
         p[k++] = t1[i++];
      }
      else
      {
         p[k++] = t2[j++];
      }
   }

   while (i < n)
   {
      p[k++] = t1[i++];
   }
   while (j < m)
   {
      p[k++] = t2[j++];
   }
}

void merge(Person *p, int left, int right)
{
   if (left < right)
   {
      int mid = left + (right - left) / 2;

      merge(p, left, mid);
      merge(p, mid + 1, right);
      mergesort(p, left, right, mid);
   }
}

int main()
{
   Person p[10] = {
       {"Alice", 75},
       {"Bob", 92},
       {"Charlie", 58},
       {"David", 83},
       {"Eve", 69},
       {"Frank", 47},
       {"Grace", 88},
       {"Hannah", 95},
       {"Ian", 62},
       {"Jack", 78}};

   merge(p, 0, 9);

   for (int i = 0; i < 5; ++i)
   {

      cout << "Name: " << p[i].name << endl;
      cout << "Time: " << p[i].racetime << endl;

      cout << endl
           << endl;
   }
   return 0;
}