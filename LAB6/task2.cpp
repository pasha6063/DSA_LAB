#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val, Node *next) : data(val), next(next) {}
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtBeginning(int val)
    {
        head = new Node(val, head);
    }
    void reverseList()
    {
        Node *prev = nullptr, *curr = head, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void printList()
    {
        for (Node *temp = head; temp; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);
    list.printList();
    list.reverseList();
    list.printList();
    return 0;
}