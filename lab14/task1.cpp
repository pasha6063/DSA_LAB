#include <iostream>
using namespace std;
class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data, Node *next = nullptr) : data(data), next(next) {}
    };
    Node *top;
    int size;

public:
    // Constructor
    Stack() : top(nullptr), size(0) {}

    // Destructor
    ~Stack()
    {
        clear();
    }

    // Push operation
    void push(const int &item)
    {
        Node *newNode = new Node(item, top);
        top = newNode;
        ++size;
    }

    // Pop operation
    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            --size;
        }
        else
        {
            cerr << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Peek operation
    int peek() const
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cerr << "Stack is empty. Cannot peek." << endl;
            throw out_of_range("Stack is empty");
        }
    }

    // Clear operation
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Check if stack is empty
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // Get size of stack
    int getSize() const
    {
        return size;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    stack.clear();
    cout << "Stack is empty: " << boolalpha << stack.isEmpty() << endl;

    return 0;
}
