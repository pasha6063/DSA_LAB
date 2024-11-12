#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int serialNumber;
    string registrationNumber;
    string name;
    int assignments[5]; 
};

// Function to perform Insertion Sort
void insertionSort(Student arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].registrationNumber > key.registrationNumber)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bubble Sort
void bubbleSort(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].registrationNumber > arr[j + 1].registrationNumber)
            {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].registrationNumber < arr[minIndex].registrationNumber)
            {
                minIndex = j;
            }
        }
        Student temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print student details
void printStudents(const Student arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Serial: " << arr[i].serialNumber
             << ", Registration: " << arr[i].registrationNumber
             << ", Name: " << arr[i].name << ", Assignments: ";
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i].assignments[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int n = 10;
    Student students[n] = {
        {1, "001", "Pasha", {85, 90, 78, 92, 88}},
        {2, "003", "Saif", {75, 80, 70, 85, 90}},
        {3, "002", "Wazir", {95, 85, 80, 90, 85}},
        {4, "006", "Abdullah", {65, 70, 60, 75, 80}},
        {5, "005", "Moon", {88, 92, 85, 90, 95}},
        {6, "009", "Shakeel", {78, 82, 75, 80, 85}},
        {7, "004", "Muzaffer", {90, 85, 88, 92, 91}},
        {8, "008", "Adnan", {70, 75, 80, 85, 90}},
        {9, "007", "Awais", {82, 88, 85, 90, 92}},
        {10, "010", "Noor", {95, 90, 92, 88, 91}}};

    cout << "Original student data: " << endl;
    printStudents(students, n);

    // Sorting using Insertion Sort in aescending order
    cout << "\nSorting using Insertion Sort (Descending)..." << endl;
    insertionSort(students, n);
    cout << "Sorted student data (Insertion Sort): " << endl;
    printStudents(students, n);

    // Sorting using Bubble Sort
    cout << "\nSorting using Bubble Sort..." << endl;
    bubbleSort(students, n);
    cout << "Sorted student data (Bubble Sort): " << endl;
    printStudents(students, n);

    // Resetting the student data for Selection Sort
    Student studentsForSelection[n] = {
        {1, "001", "Pasha", {85, 90, 78, 92, 88}},
        {2, "003", "Saif", {75, 80, 70, 85, 90}},
        {3, "002", "Wazir", {95, 85, 80, 90, 85}},
        {4, "006", "Abdullah", {65, 70, 60, 75, 80}},
        {5, "005", "Moon", {88, 92, 85, 90, 95}},
        {6, "009", "Shakeel", {78, 82, 75, 80, 85}},
        {7, "004", "Muzaffer", {90, 85, 88, 92, 91}},
        {8, "008", "Adnan", {70, 75, 80, 85, 90}},
        {9, "007", "Awais", {82, 88, 85, 90, 92}},
        {10, "010", "Noor", {95, 90, 92, 88, 91}}};

    // Sorting using Selection Sort
    cout << "\nSorting using Selection Sort..." << endl;
    selectionSort(studentsForSelection, n);
    cout << "Sorted student data (Selection Sort): " << endl;
    printStudents(studentsForSelection, n);

    return 0;
}