#include <iostream>
#include <string>
using namespace std;

struct Node
{
   string name;
   int price;
   Node *next;

   Node(string n, int p)
   {
      name = n;
      price = p;
      next = nullptr;
   }
};

void insertFront(Node *&head, string name, int price)
{
   Node *newItem = new Node(name, price);
   newItem->next = head;
   head = newItem;
}

void insertEnd(Node *&head, string name, int price)
{
   Node *newItem = new Node(name, price);
   if (head == nullptr)
   {
      head = newItem;
      return;
   }
   Node *temp = head;
   while (temp->next != nullptr)
   {
      temp = temp->next;
   }
   temp->next = newItem;
}

void insertAfter(Node *head, string target, string name, int price)
{
   Node *temp = head;
   while (temp != nullptr && temp->name != target)
   {
      temp = temp->next;
   }
   if (temp != nullptr)
   {
      Node *newItem = new Node(name, price);
      newItem->next = temp->next;
      temp->next = newItem;
   }
}

void searchItem(Node *head, string target)
{
   Node *temp = head;
   while (temp != nullptr)
   {
      if (temp->name == target)
      {
         cout << "Item found: " << temp->name << " costs $" << temp->price << endl;
         return;
      }
      temp = temp->next;
   }
   cout << target << " not found in the cart." << endl;
}

void displayCart(Node *head)
{
   cout << "\n🛒 Shopping Cart Contents:\n";
   Node *temp = head;
   while (temp != nullptr)
   {
      cout << "- " << temp->name << " : $" << temp->price << endl;
      temp = temp->next;
   }
   cout << endl;
}

int main()
{
   
   Node *cart = new Node("Laptop", 1000);
   cart->next = new Node("Phone", 700);
   cart->next->next = new Node("Tablet", 400);
   cart->next->next->next = new Node("Headphones", 150);

   cout << "Initial cart:";
   displayCart(cart);

   insertFront(cart, "Smartwatch", 200);
   cout << "Added Smartwatch at the front.";
   displayCart(cart);

   insertEnd(cart, "Keyboard", 80);
   cout << "Added Keyboard at the end.";
   displayCart(cart);

   insertAfter(cart, "Phone", "Monitor", 300);
   cout << "Inserted Monitor after Phone.";
   displayCart(cart);

   cout << "Searching for Tablet...\n";
   searchItem(cart, "Tablet");

   cout << "Final cart:";
   displayCart(cart);

   return 0;
}
