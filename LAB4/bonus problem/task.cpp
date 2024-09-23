#include <iostream>
using namespace std;

// Linear Search (Unsorted)
int linearSearch(string names[], string target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (names[i] == target)
        {
            return i;
        }
    }
    return -1; // not found
}

// Binary Search (Sorted)
int binarySearch(string names[], string target, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (names[mid] == target)
        {
            return mid;
        }
        else if (names[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // not found
}

// Bubble Sort (for sorting the array)
void bubbleSort(string names[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (names[j] > names[j + 1])
            {
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of contacts: ";
    cin >> n;

    string *names = new string[n];
    string *numbers = new string[n];
    cout << "Enter the names and numbers of the contacts: ";
    for (int i = 0; i < n; i++)
    {
        cin >> names[i] >> numbers[i];
    }

    // Linear Search (Unsorted)
    cout << "Enter the name to search (linear search): ";
    string targetLinear;
    cin >> targetLinear;
    int resultLinear = linearSearch(names, targetLinear, n);
    if (resultLinear != -1)
    {
        cout << "Found at index: " << resultLinear << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // Binary Search (Sorted)
    cout << "Enter the name to search (binary search): ";
    string targetBinary;
    cin >> targetBinary;
    bubbleSort(names, n); // sort the array for binary search
    int resultBinary = binarySearch(names, targetBinary, 0, n - 1);
    if (resultBinary != -1)
    {
        cout << "Found at index: " << resultBinary << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    delete[] names;
    delete[] numbers;

    return 0;
}