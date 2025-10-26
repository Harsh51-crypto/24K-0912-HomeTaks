#include <iostream>
#include <stack>
using namespace std;

struct Node {
    string site;
    Node* next;
    Node(string s) : site(s), next(NULL) {}
};

void display(Node* head) {
    cout << "\nCurrent History:\n";
    for (Node* p = head; p; p = p->next)
        cout << p->site << " ";
    cout << endl;
}

int main() {
    stack<string> history;
    Node* head = NULL;
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (auto s : sites) {
        Node* n = new Node(s);
        n->next = head;
        head = n;
        history.push(s);
    }
    display(head);

    history.pop();
    history.pop();
    head = head->next->next;

    cout << "\nAfter pressing back twice:\n";
    display(head);
    cout << "Current Page: " << head->site;
}
