#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int price;
    Node* next;
    Node(string n, int p) {
        name = n;
        price = p;
        next = nullptr;
    }
};

void addToTail(Node*& head, string name, int price) {
    Node* newItem = new Node(name, price);
    if (head == nullptr) {
        head = newItem;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newItem;
}

void deleteFromFront(Node*& head) {
    if (head == nullptr) {
        cout << "Cart is empty, nothing to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Removed: " << temp->name << " ($" << temp->price << ") from the cart.\n";
    delete temp;
}

void searchByName(Node* head, string target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->name == target) {
            cout << "Item found: " << temp->name << " costs $" << temp->price << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << target << "\" not found in the cart.\n";
}

void searchByPosition(Node* head, int pos) {
    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }
    Node* temp = head;
    int index = 1;
    while (temp != nullptr && index < pos) {
        temp = temp->next;
        index++;
    }
    if (temp != nullptr) {
        cout << "At position " << pos << ": " << temp->name 
             << " costs $" << temp->price << endl;
    } else {
        cout << "No item found at position " << pos << ".\n";
    }
}

void displayCart(Node* head) {
    if (head == nullptr) {
        cout << "🛒 Your cart is empty.\n";
        return;
    }
    cout << "\n🛒 Shopping Cart:\n";
    Node* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". " << temp->name << " - $" << temp->price << endl;
        temp = temp->next;
        index++;
    }
    cout << endl;
}

int main() {
    Node* cart = nullptr;

    addToTail(cart, "Laptop", 1000);
    addToTail(cart, "Phone", 700);
    addToTail(cart, "Tablet", 400);
    addToTail(cart, "Headphones", 150);

    displayCart(cart);

    cout << "\nAdding Smartwatch ($200) to the cart...";
    addToTail(cart, "Smartwatch", 200);
    displayCart(cart);

    cout << "Deleting the first item from the cart...\n";
    deleteFromFront(cart);
    displayCart(cart);

    cout << "Searching for 'Tablet'...\n";
    searchByName(cart, "Tablet");

    cout << "Searching for item at position 3...\n";
    searchByPosition(cart, 3);

    return 0;
}
