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

void deleteAtBegining(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    delete temp;
}

void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = *head;
    int currentPosition = 1;
    while (temp->next != NULL && currentPosition < position)
    {
        temp = temp->next;
        currentPosition++;
    }

    if (currentPosition != position)
    {
        cout << "Position out of range." << endl;
        return;
    }

    Node *nodeToDelete = temp;
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete nodeToDelete;
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

    // Deleting from an empty list
    cout << "Deleting from an empty list:" << endl;
    deleteAtBegining(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 1);

    // Inserting at a position greater than the length of the list
    cout << "\nInserting at a position greater than the length of the list:" << endl;
    insertAtPosition(&head, 5, 10);
    insertAtBegining(&head, 20);
    insertAtBegining(&head, 30);
    printForward(head);
    printBackward(head);

    // Deleting all nodes one by one and trying further deletions
    cout << "\nDeleting all nodes one by one and trying further deletions:" << endl;
    deleteAtBegining(&head);
    printForward(head);
    printBackward(head);
    deleteAtBegining(&head);
    printForward(head);
    printBackward(head);
    deleteAtBegining(&head);
    printForward(head);
    printBackward(head);
    deleteAtBegining(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 1);

    return 0;
}