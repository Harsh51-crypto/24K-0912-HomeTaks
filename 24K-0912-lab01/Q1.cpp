#include <iostream>
using namespace std;

class ResearchPaper
{

public:
   string *authorName;
   int size;

   ResearchPaper(int size) : size(size)
   {
      authorName = new string[this->size];
   }

   ~ResearchPaper()
   {
      delete[] authorName;
   }

   ResearchPaper &operator=(const ResearchPaper &obj)
   {

      this->size = obj.size;

      authorName = new string[size];

      for (int i = 0; i < size; ++i)
      {
         authorName[i] = obj.authorName[i];
      }

      return *(this);
   }

   ResearchPaper(const ResearchPaper &obj)
   {

      this->size = obj.size;

      authorName = new string[size];

      for (int i = 0; i < size; ++i)
      {
         authorName[i] = obj.authorName[i];
      }
   }

   void print()
   {
      for (int i = 0; i < size; ++i)
      {
         cout << authorName[i] << " ";
      }
      cout << endl;
   }
};
int main()
{

   ResearchPaper r1(5);
   cout << "Input of Author Names: " << endl;
   for (int i = 0; i < r1.size; ++i)
   {
      getline(cin, r1.authorName[i]);
   }

   ResearchPaper r2(r1);

   string update;
   cout << "Enter a String to Update Object 2: " << endl;
   getline(cin, update);
   r2.authorName[0] = update;

   cout << "Object 1: " << endl;
   r1.print();

   cout << "Object 2: " << endl;
   r2.print();

   return 0;
}