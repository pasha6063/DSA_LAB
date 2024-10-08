#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void insertAtBegining(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtTail(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printForward(Node *node)
{
    cout << "Forward traversal: ";
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void printBackward(Node *node)
{
    if (node == NULL)
        return;

    // Move to the last node
    while (node->next != NULL)
    {
        node = node->next;
    }

    cout << "Backward traversal: ";
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->prev;
    }
    cout << "NULL" << endl;
}
void deleteFromEnd(Node **head)
{
    if (*head == NULL)
        return;
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL; // The list had only one head
    }
    delete temp;
}
void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ->";
        node = node->next;
    }
    cout << "NULL " << endl;
}

int main()
{
    Node *head = NULL;
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);
    insertAtBegining(&head, 30);
    insertAtBegining(&head, 20);
    insertAtBegining(&head, 10);

    printForward(head);
    printBackward(head);
    deleteFromEnd(&head);
    printList(head);

    return 0;
}