#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insertAtEnd(Node **head, int newdata)
{
    Node *newNode = new Node();
    newNode->data = newdata;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
void reverselist(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void findmiddle(Node *head)
{
    if (head == NULL)
    {
        cout << "The linked list is empty " << endl;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle node is " << slow->data << endl;
}
void printList(Node *node)
{
    cout << "LInked list elements" << endl;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL;
    int n, value;
    cout << "how many values do you want to enter in the list ?"<<endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value :" << i + 1<<"=";
        cin >> value;
        insertAtEnd(&head, value);
    }
    
    cout << "Linked List is " << endl;
    findmiddle(head);
    printList(head);
}
