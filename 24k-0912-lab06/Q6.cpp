#include <iostream>
#include <queue>
using namespace std;

struct Order
{
   string item;
   int qty;
};

int main()
{
   queue<Order> q;
   int choice;
   do
   {
      cout << "1. Add Order\n2. Process Order\n3. Show Orders\n4. Exit\n";
      cin >> choice;
      if (choice == 1)
      {
         Order o;
         cout << "Enter Item and Quantity: ";
         cin >> o.item >> o.qty;
         q.push(o);
      }
      else if (choice == 2 && !q.empty())
      {
         cout << "Processed: " << q.front().item << endl;
         q.pop();
      }
      else if (choice == 3)
      {
         queue<Order> temp = q;
         cout << "Pending Orders:\n";
         while (!temp.empty())
         {
            cout << temp.front().item << " x" << temp.front().qty << endl;
            temp.pop();
         }
      }
   } while (choice != 4);
}
