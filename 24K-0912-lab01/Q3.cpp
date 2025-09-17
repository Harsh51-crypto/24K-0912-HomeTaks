#include <iostream>
using namespace std;
class Exam
{

public:
   int *marks;
   int size;

   Exam(int size) : size(size)
   {
      marks = new int[size];
   }

   ~Exam()
   {
      delete[] marks;
   }

   void print()
   {
      for (int i = 0; i < size; ++i)
      {
         cout << marks[i] << " ";
      }
   }
};
int main()
{

   Exam e1(5);

   cout << "Taking input! " << endl;
   for (int i = 0; i < e1.size; ++i)
   {
      cin >> e1.marks[i];
   }

   Exam e2(e1);
   cout << "Changing Marks in Object 2 By increment of 1: " << endl;
   for (int i = 0; i < e2.size; ++i)
   {
      e2.marks[i]++;
   }

   cout<<"object 1: "<<endl;
   e1.print();
   cout << endl;
   cout<<"object 2: "<<endl;
   e2.print();

   return 0;
}
