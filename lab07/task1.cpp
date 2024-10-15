#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    void insertNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *lastNode = head;
            while (lastNode->next != head)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            newNode->next = head;
        }
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *tempNode = head;
        do
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        } while (tempNode != head);
        cout << endl;
    }
};
int main()
{
    CircularLinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
    cout << "Elements in the circular linked list: ";
    list.printList();
    return 0;
}