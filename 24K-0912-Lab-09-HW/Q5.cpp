#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) { key = k; left = right = NULL; height = 1; }
};

int getHeight(Node* n) { return n ? n->height : 0; }
int getBF(Node* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBF(root);

    if (bf > 1 && key < root->left->key) return rightRotate(root);
    if (bf < -1 && key > root->right->key) return leftRotate(root);
    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printBF(Node* r) {
    if (!r) return;
    printBF(r->left);
    cout << "Node " << r->key << " BF = " << getBF(r) << endl;
    printBF(r->right);
}

void printTree(Node* root, string space = "", bool last = true) {
    if (!root) return;
    cout << space;
    if (last) { cout << "R----"; space += "     "; }
    else { cout << "L----"; space += "|    "; }
    cout << root->key << endl;
    printTree(root->left, space, false);
    printTree(root->right, space, true);
}

int main() {
    Node* root = NULL;
    int arr[] = {40,30,50,25,35,45,60};
    for (int x : arr) root = insertNode(root, x);

    root = insertNode(root, 55);

    cout << "Task 1 Final Tree\n";
    printTree(root);
    printBF(root);
}
