#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
int getMiddle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;

        slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}

int main()
{

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node *head = nullptr;
    Node *temp = nullptr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    cout << "Middle element is: " << getMiddle(head) << endl;
    return 0;
}