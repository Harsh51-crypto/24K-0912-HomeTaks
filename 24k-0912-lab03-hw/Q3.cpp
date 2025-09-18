#include <iostream>
using namespace std;
class Node
{

public:
   int id;
   Node *next;
   Node *prev;
   string name;
   double price;

   Node(int id, string name, double price) : id(id), name(name), price(price)
   {
      next = NULL;
      prev = NULL;
   }

   ~Node()
   {
      if (next != NULL || prev != NULL)
      {
         next = NULL;
         prev = NULL;
      }
   }
};

class DLL
{

public:
   Node *head;
   Node *tail;

   DLL()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtTail(string name, int id, double price)
   {
      Node *temp = new Node(id, name, price);
      if (tail != NULL)
      {
         tail->next = temp;
         tail->next->prev = tail;
         tail = temp;
         return;
      }
      tail = temp;
      head = temp;
   }

   void insertAtHead(string name, int id, double price)
   {

      Node *temp = new Node(id, name, price);

      if (head != NULL)
      {

         temp->next = head;
         temp->next->prev = temp;
         head = temp;
         return;
      }
      head = temp;
      tail = temp;
   }

   void DeleteAtFirst()
   {

      Node *current = head;
      head = head->next;
      head->prev = NULL;
      delete current;
   }

   void DeleteAtLast()
   {
      Node *current = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete current;
   }

   bool search(int id)
   {

      Node *temp = head;

      while (temp != NULL)
      {

         if (temp->id == id)
         {
            modifiy(temp);
            return true;
         }
         temp = temp->next;
      }
      return false;
   }

   void modifiy(Node *&node)
   {

      if (node != NULL)
      {
         double price;
         cin >> price;
         node->price = price;
         cout << "Item Found: " << node->name << " " << " and price updated to: " << price << endl;
      }
   }

   void displayFront()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->name << " " << temp->id << " " << temp->price << endl;
         temp = temp->next;
      }
   }

   void displayBack()
   {

      Node *temp = tail;
      while (temp != NULL)
      {
         cout << temp->name << " " << temp->id << " " << temp->price << endl;
         temp = temp->prev;
      }
   }

   int Total()
   {
      Node *temp = head;
      int count = 0;
      while (temp != NULL)
      {
         ++count;
         temp = temp->next;
      }
      return count;
   }

   double Expensive()
   {
      Node *temp = head;
      double max = -1.00;
      while (temp != NULL)
      {
         if (max < temp->price)
         {
            max = temp->price;
         }
         temp = temp->next;
      }
      return max;
   }
};
int main()
{

   DLL dl;
   dl.insertAtTail("Laptop", 100, 20000);
   cout << "Initial Items: " << endl;
   dl.displayFront();

   cout<<endl;

   cout << "Inserting At Front: " << endl;
   dl.insertAtHead("Computer", 101, 3000);

   dl.displayFront();

   cout << "\nInserting At End: " << endl;
   dl.insertAtTail("Mobile", 102, 9000);

   dl.displayFront();
   dl.search(100);

   dl.displayFront();

   cout << endl;
   dl.displayBack();

   cout << "Total items: " << dl.Total() << endl;

   cout << "Most Expensive Item price is: " << dl.Expensive() << endl;

   return 0;
}