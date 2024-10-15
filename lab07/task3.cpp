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
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
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
            newNode->next = head;
            head = newNode;
            lastNode->next = head;
        }
    }
    void deleteNode(int data)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        if (head->data == data)
        {
            Node *lastNode = head;
            while (lastNode->next != head)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = head->next;
            Node *tempNode = head;
            head = head->next;
            delete tempNode;
            return;
        }

        Node *prevNode = head;
        Node *currNode = head->next;
        while (currNode != head)
        {
            if (currNode->data == data)
            {
                prevNode->next = currNode->next;
                delete currNode;
                return;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }

        cout << "Node with value " << data << " not found in the list." << endl;
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
    list.deleteNode(3);
    cout << "Elements in the circular linked list after deleting node with value 3: ";
    list.printList();
    return 0;
}