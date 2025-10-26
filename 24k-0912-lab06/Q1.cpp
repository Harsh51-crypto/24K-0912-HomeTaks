#include <iostream>
#include <stack>
using namespace std;

struct Call {
    string name;
    string number;
    int duration;
};

void display(stack<Call> s) {
    cout << "\nCurrent Call Log:\n";
    if (s.empty()) cout << "No call history\n";
    while (!s.empty()) {
        Call c = s.top();
        cout << c.name << " | " << c.number << " | " << c.duration << " mins\n";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<Call> callStack;
    int choice;
    do {
        cout << "1. Add Call\n2. Delete Last Call\n3. Show Last Call\n4. Check if Empty\n5. Exit\n";
        cin >> choice;
        if (choice == 1) {
            Call c;
            cout << "Enter Name Number Duration: ";
            cin >> c.name >> c.number >> c.duration;
            callStack.push(c);
        } else if (choice == 2 && !callStack.empty()) {
            callStack.pop();
        } else if (choice == 3 && !callStack.empty()) {
            Call c = callStack.top();
            cout << "Last Call: " << c.name << " " << c.number << " " << c.duration << " mins\n";
        } else if (choice == 4) {
            cout << (callStack.empty() ? "Empty\n" : "Not Empty\n");
        }
        display(callStack);
    } while (choice != 5);
}
