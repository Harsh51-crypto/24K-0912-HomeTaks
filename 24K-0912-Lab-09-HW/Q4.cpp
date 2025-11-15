#include <vector>
#include <iostream>
using namespace std;

class Node
{

public:
   Node *left;
   Node *right;
   int data;

   Node(int data) : data(data)
   {
      right = left = NULL;
   }
};

Node *leftrotate(Node *root)
{

   Node *x = root->right;
   Node *temp = x->left;
   x->left = root;
   root->right = temp;

   return x;
}

Node *rightrotate(Node *root)
{

   Node *x = root->left;
   Node *temp = x->right;

   x->right = root;
   root->left = temp;

   return x;
}

int height(Node *root)
{
   if (root == NULL)
   {
      return 0;
   }

   int left = height(root->left);
   int right = height(root->right);
   int ans = max(left, right) + 1;
   return ans;
}

int getbalanceFactor(Node *root)
{

   int left = height(root->left);
   int right = height(root->right);

   return left - right;
}

Node *insert(Node *&root, int data)
{
   if (root == NULL)
   {
      root = new Node(data);
      return root;
   }

   if (root->data < data)
   {
      root->right = insert(root->right, data);
   }
   else if (root->data > data)
   {
      root->left = insert(root->left, data);
   }

   int balance = getbalanceFactor(root);

   if (balance > 1 && getbalanceFactor(root->left) >= 0)
   {
      cout << "Right Rotation: " << root->data << endl;

      return rightrotate(root);
   }

   if (balance < -1 && getbalanceFactor(root->right) <= 0)
   {
      cout << "Left Rotation: " << root->data << endl;
      return leftrotate(root);
   }

   if (balance > 1 && getbalanceFactor(root->left) < 0)
   {
      cout << "Left Rotation on : " << root->left->data << endl;
      root->left = leftrotate(root->left);
      cout << "Right Rotation on : " << root->data << endl;
      return rightrotate(root->right);
   }
   if (balance < -1 && getbalanceFactor(root->right) > 0)
   {
      cout << "Right Rotation on : " << root->right->data << endl;
      root->right = rightrotate(root->right);
      cout << "Left Rotation on : " << root->data << endl;
      return leftrotate(root);
   }

   return root;
}

void inorder(Node *&root)
{

   if (root == NULL)
   {
      return;
   }

   inorder(root->left);
   cout << root->data << " ";
   inorder(root->right);
}

void BF(Node *root)
{
   if (root == NULL)
      return;

   BF(root->left);
   cout << "Balance Factor of: " << root->data << " is: " << getbalanceFactor(root) << " " << "Height is: " << height(root) << endl;
   BF(root->right);
}

void solve()
{

   Node *root = NULL;

   insert(root, 15);
   insert(root, 10);
   insert(root, 20);
   insert(root, 8);
   insert(root, 12);
   insert(root, 25);
   insert(root, 30);
   cout << "Before Inserting 16: " << endl;
   inorder(root);
   cout << endl
        << "After inserting 16: " << endl;
   insert(root, 16);
   cout << endl
        << endl;
   BF(root);

   cout << endl
        << endl;
   inorder(root);
}

int main()
{
   int t, i = 1;
   cin >> t;
   while (t--)
   {
      cout << "Case #" << i << endl;
      solve();
      ++i;
   }
   return 0;
}