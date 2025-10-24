#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};


void insert(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


int getMax(Node* head) {
    int maxVal = 0;
    for (Node* temp = head; temp; temp = temp->next)
        if (temp->score > maxVal)
            maxVal = temp->score;
    return maxVal;
}


int getDigit(int num, int place) {
    return (num / place) % 10;
}


void radixSort(Node*& head) {
    if (!head || !head->next)
        return;

    int maxVal = getMax(head);

   
    for (int place = 1; maxVal / place > 0; place *= 10) {
        Node* buckets[10] = {nullptr};
        Node* tails[10] = {nullptr};

        
        for (Node* temp = head; temp; ) {
            int digit = getDigit(temp->score, place);
            Node* nextNode = temp->next;
            temp->next = nullptr;

            if (!buckets[digit])
                buckets[digit] = tails[digit] = temp;
            else {
                tails[digit]->next = temp;
                tails[digit] = temp;
            }
            temp = nextNode;
        }

        
        head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < 10; ++i) {
            if (!buckets[i]) continue;
            if (!head) {
                head = buckets[i];
                tail = tails[i];
            } else {
                tail->next = buckets[i];
                tail = tails[i];
            }
        }
    }
}


void display(Node* head) {
    cout << "\nSorted Students (Ascending by Score):\n";
    cout << "--------------------------------------\n";
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->name << " - " << temp->score << endl;
}

int main() {
    Node* head = nullptr;

    
    insert(head, "Alice", 75);
    insert(head, "Bob", 92);
    insert(head, "Charlie", 58);
    insert(head, "Daisy", 100);
    insert(head, "Ethan", 83);
    insert(head, "Frank", 9);

    cout << "Before Sorting:\n";
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->name << " - " << temp->score << endl;

    radixSort(head);
    display(head);

    return 0;
}
