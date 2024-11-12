#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input() {
        cout << "\nEnter person id: ";
        cin >> per_id;
        cout << "Enter person name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter person age: ";
        cin >> per_age;
    }

    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << "\n";
    }

    int getId() const { return per_id; } 
};

class Node {
public:
    Person data;
    Node* next;
    bool isHead; 

    Node(Person p, bool head) : data(p), next(nullptr), isHead(head) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(Person p) {
        Node* newNode = new Node(p, true);
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode; 
        }

        cout << "Person added at the head of the list!\n";
    }

    void insertAtTail(Person p) {
        Node* newNode = new Node(p, false);
        if (tail == nullptr) {
            head = tail = newNode; 
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Person added at the tail of the list!\n";
    }

    void displayList() const {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            temp->data.output();
            cout << (temp->isHead ? "(Inserted at Head)" : "(Inserted at Tail)") << "\n";
            temp = temp->next;
        }
    }


};

int main() {
    LinkedList list;
    int choice;

    while (true) {
        cout << "\nLinked List Menu:\n";
        cout << "1. Add a person at the head of the list\n";
        cout << "2. Add a person at the tail of the list\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Person p;
            p.input();
            list.insertAtHead(p);
        } else if (choice == 2) {
            Person p;
            p.input();
            list.insertAtTail(p);
        } else if (choice == 3) {
            list.displayList();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}