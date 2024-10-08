#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string data;
    Node *next;
    Node *prev;
    Node(string songName) : data(songName), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtEnd(string songName)
    {
        Node *newNode = new Node(songName);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void traverseForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void traverseBackward()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void deleteSong(string songName)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == songName)
            {
                if (temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }

                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                else
                {
                    tail = temp->prev;
                }

                delete temp;
                cout << "Song deleted successfully!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found in the playlist!" << endl;
    }
};

class Playlist : public DoublyLinkedList
{
public:
    void addSongToEnd(string songName)
    {
        insertAtEnd(songName);
    }

    void deleteSong(string songName)
    {
        DoublyLinkedList::deleteSong(songName);
    }

    void nextSong()
    {
        cout << "Next song: ";
        DoublyLinkedList::traverseForward();
    }

    void previousSong()
    {
        cout << "Previous song: ";
        DoublyLinkedList::traverseBackward();
    }
};

int main()
{
    Playlist playlist;

    while (true)
    {
        cout << "1. Add a new song to the end of the playlist." << endl;
        cout << "2. Traverse the playlist both forwards and backwards (next/previous song)." << endl;
        cout << "3. Delete a song from the playlist." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string songName;
            cout << "Enter the song name: ";
            cin >> songName;
            playlist.addSongToEnd(songName);
            break;
        }
        case 2:
        {
            cout << "1. Next song" << endl;
            cout << "2. Previous song" << endl;
            cout << "Enter your choice: ";

            int songChoice;
            cin >> songChoice;

            switch (songChoice)
            {
            case 1:
                playlist.nextSong();
                break;
            case 2:
                playlist.previousSong();
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
            break;
        }
        case 3:
        {
            string songName;
            cout << "Enter the song name to delete: ";
            cin >> songName;
            playlist.deleteSong(songName);
            break;
        }
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}