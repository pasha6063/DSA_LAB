#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
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

// Function to perform in-order traversal
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function to perform pre-order traversal
void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function to perform post-order traversal
void postOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = nullptr;
    int nodes, n;

    cout << "Enter the number of nodes you want to enter: ";
    cin >> nodes;

    // Insert nodes into the BST based on user input
    for (int i = 0; i < nodes; i++)
    {
        cout << "Enter the value for Node " << i + 1 << ": ";
        cin >> n;
        root = insert(root, n);
    }

    cout << "In-order traversal of the BST:" << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal of the BST:" << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal of the BST:" << endl;
    postOrderTraversal(root);

    return 0;
}