#include <iostream>
#include <queue>
using namespace std;

int main()
{
   queue<string> patrons;
   int choice;
   do
   {
      cout << "1. Add Patron\n2. Complete Transaction\n3. Show Queue\n4. Exit\n";
      cin >> choice;
      if (choice == 1)
      {
         string name;
         cout << "Enter Patron Name: ";
         cin >> name;
         patrons.push(name);
      }
      else if (choice == 2 && !patrons.empty())
      {
         cout << patrons.front() << " transaction completed\n";
         patrons.pop();
      }
      else if (choice == 3)
      {
         queue<string> temp = patrons;
         cout << "Current Queue:\n";
         while (!temp.empty())
         {
            cout << temp.front() << endl;
            temp.pop();
         }
      }
   } while (choice != 4);
}
