#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value < root->data)
    {

        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "In-oder traversal of the BST:" << endl;
    inOrderTraversal(root);
    cout << endl;
    return 0;
}