#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node *&head, int val)
{
    Node *new_node = new Node(val);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insertionAtPosition(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }

    Node *new_node = new Node(val);
    Node *temp = head;
    int current_pos = 0;
    while (current_pos != pos - 1 && temp != NULL)
    {
        temp = temp->next;
        current_pos++;
    }

    if (temp == NULL)
    {
        cout << "Invalid position. Insertion failed." << endl;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(Node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->val == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->val != val)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Value not found." << endl;
        return;
    }

    Node *to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
}

bool searchNode(Node *head, int val)
{
    Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->val == val)
        {
            cout << "Value " << val << " found at index " << index << endl;
            return true;
        }
        temp = temp->next;
        index++;
    }
    cout << "Value not found." << endl;
    return false;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value;
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    display(head);

    int choice;
    while (true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Searching\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int insert_value, insert_pos;
            cout << "Enter the value to insert: ";
            cin >> insert_value;
            cout << "Enter the position to insert at (0-based): ";
            cin >> insert_pos;
            insertionAtPosition(head, insert_value, insert_pos);
            display(head);
            break;
        case 2:
            int delete_value;
            cout << "Enter the value to delete: ";
            cin >> delete_value;
            deleteNode(head, delete_value);
            display(head);
            break;
        case 3:
            int search_value;
            cout << "Enter the value to search: ";
            cin >> search_value;
            searchNode(head, search_value);
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}