#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   int TicketId;
   string name;
   string Ridername;
   Node *next;

   Node(int id, string name, string rider) : TicketId(id), name(name), Ridername(rider)
   {
      next = NULL;
   }
};

class CLL
{

public:
   Node *head;
   Node *tail;

   CLL()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtHead(Node *&head, int id, string name, string ridername)
   {
      Node *temp = new Node(id, name, ridername);

      if (head != NULL)
      {
         temp->next = head;
         head->next = temp;
         head = temp;
         return;
      }
      head = temp;
      head->next = head;
      tail = head;
   }

   void insertAtTail(Node *&tail, int id, string name, string ridername)
   {
      Node *temp = new Node(id, name, ridername);

      if (tail != NULL)
      {
         tail->next = temp;
         tail = temp;
         tail->next = head;
         return;
      }
      tail = temp;
      tail->next = tail;
      head = tail;
   }

   void print(Node *&head)
   {
      Node *temp = head;

      do
      {
         cout << temp->name << " " << temp->TicketId << " " << temp->Ridername << endl;
         temp = temp->next;
      } while (temp != head);
   }

   void cancelFirstTicket()
   {

      Node *temp = head;
      head = head->next;
      tail->next = head;
      delete temp;
   }

   void cancelTicket(int id)
   {
      int count = 0;

      Node *current = head, *prev = NULL;
      while (current != NULL)
      {
         count++;

         if (current->TicketId == id)
         {
            if (count == 1)
            {
               cancelFirstTicket();
               return;
            }
            prev->next = current->next;
            delete current;
            break;
         }
      }
   }

   bool search(int id)
   {

      Node *temp = head;

      do
      {
         if (temp->TicketId == id)
         {
            cout << temp->name << " " << temp->TicketId << " " << temp->Ridername << endl;
            return true;
         }
         temp = temp->next;
      } while (temp != head);

      return false;
   }

   int Total()
   {
      Node *temp = head;
      int count = 0;
      do
      {

         ++count;
         temp = temp->next;
      } while (temp != head);

      return count;
   }

   void NextTicket(int id)
   {
      Node *temp = head;

      do
      {
         if (temp->TicketId == id)
         {
            cout << temp->next->name << " " << temp->next->Ridername << " " << endl;
            break;
         }

      } while (temp != head);
   }
};



int main()
{

 
    CLL tickets;

    
    tickets.insertAtHead(tickets.head, 1, "RollerCoaster", "Alice");
    tickets.insertAtTail(tickets.tail, 2, "FerrisWheel", "Bob");
    tickets.insertAtTail(tickets.tail, 3, "HauntedHouse", "Charlie");
    tickets.insertAtTail(tickets.tail, 4, "BumperCars", "David");

    cout << "All Tickets:" << endl;
    tickets.print(tickets.head);

    cout << "\nSearching for Ticket ID 3:" << endl;
    if (!tickets.search(3))
        cout << "Ticket not found!" << endl;

    cout << "\nTotal Tickets: " << tickets.Total() << endl;

    cout << "\nNext Ticket after ID 2:" << endl;
    tickets.NextTicket(2);

    cout << "\nCancelling first ticket..." << endl;
    tickets.cancelFirstTicket();
    tickets.print(tickets.head);

    cout << "\nCancelling Ticket ID 3..." << endl;
    tickets.cancelTicket(3);
    tickets.print(tickets.head);

    cout << "\nTotal Tickets after cancellations: " << tickets.Total() << endl;

    return 0;
}

