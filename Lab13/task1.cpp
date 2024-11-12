#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input()
    {
        cout << "\nEnter person id: ";
        cin >> per_id;
        cout << "Enter person name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter person age: ";
        cin >> per_age;
    }

    void output()
    {
        cout << "\nPerson details:\n"
             << "ID: " << per_id << "\n"
             << "Name: " << per_name << "\n"
             << "Age: " << per_age << "\n";
    }
};

class Node
{
public:
    Person data; 
    Node *next;  
    Node(Person p) : data(p), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head; 

public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(Person p)
    {
        Node *newNode = new Node(p);
        newNode->next = head; 
        head = newNode;      
        cout << "Person added at the head of the list!\n";
    }

   
    void displayList()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data.output();
            temp = temp->next;
        }
    }

};

int main()
{
    LinkedList list;
    int choice;

    while (true)
    {
        cout << "\nLinked List Menu:\n";
        cout << "1. Add a person at the head of the list\n";
        cout << "2. Display the list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Person p;
            p.input();
            list.insertAtHead(p);
        }
        else if (choice == 2)
        {
            list.displayList();
        }
        else if (choice == 3)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}