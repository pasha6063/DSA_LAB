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
    cout << "Forward traversal: "<<endl;
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

    cout << "Backward traversal: "<<endl;
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
    deleteAtBegining(&head);
    printForward(head);
    printBackward(head);
    deleteAtEnd(&head);
    printForward(head);
    printBackward(head);
    deleteAtPosition(&head, 2);
    printForward(head);
    printBackward(head);

    return 0;
}