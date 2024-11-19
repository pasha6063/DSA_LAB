#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    const int MAX_SIZE = 5; // Maximum size of the queue

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isFull()
    {
        return size == MAX_SIZE;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue already has many elements (Overflow).\n";
            return;
        }
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Added " << value << " to the queue.\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue doesn't have any elements (Underflow).\n";
            return -1;
        }

        Node *temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        size--;
        cout << "Removed " << value << " from the queue.\n";
        return value;
    }

    int count()
    {
        return size;
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
        cout << "Queue cleared.\n";
    }
};

int main()
{
    Queue queue1, queue2;
    int choice, value;
    cout << "\t NAME : Ghazanfar Pasha\t" << endl;
    cout << "\t SAP ID : 55590\t" << endl;
    while (true)
    {
        cout << "1. Add to Queue 1." << endl;
        cout << "2. Remove from Queue 1 and Add to Queue 2." << endl;
        cout << "3. Remove from Queue 2." << endl;
        cout << "4. Display number of elements in Queue 1." << endl;
        cout << "5. Clear Queue 1." << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter a value to add to Queue 1: ";
            cin >> value;
            queue1.enqueue(value);
        }
        else if (choice == 2)
        {
            value = queue1.dequeue();
            if (value != -1)
            {
                queue2.enqueue(value);
            }
        }
        else if (choice == 3)
        {
            queue2.dequeue();
        }
        else if (choice == 4)
        {
            cout << "Number of elements in Queue 1: " << queue1.count() << endl;
        }
        else if (choice == 5)
        {
            queue1.clear();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
