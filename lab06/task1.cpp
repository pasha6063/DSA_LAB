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

void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(Node **head, int position, int newData)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = *head;
    int currentPosition = 1;
    while (temp->next != NULL && currentPosition < position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }

    if (currentPosition != position - 1)
    {
        cout << "Position out of range." << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
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

int main()
{
    Node *head = NULL;
    insertAtBegining(&head, 10);
    insertAtBegining(&head, 20);
    insertAtBegining(&head, 30);
    printForward(head);
    printBackward(head);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printForward(head);
    printBackward(head);
    insertAtPosition(&head, 3, 35);
    printForward(head);
    printBackward(head);

    return 0;
}