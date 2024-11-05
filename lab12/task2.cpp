#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to select a random pivot and partition the array
int partition(vector<int> &arr, int low, int high)
{
    // Select a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[low]); // Move the pivot to the start

    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    // Place the pivot in its correct position
    swap(arr[low], arr[i - 1]);
    return i - 1; // Return the index of the pivot
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    vector<int> arr1 = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    vector<int> arr2 = arr1; // Create a copy for comparison
    int n = arr1.size();

    // Sort using the original implementation (first element as pivot)
    cout << "Original array: ";
    printArray(arr1);

    clock_t start1 = clock();
    quicksort(arr1, 0, n - 1);
    clock_t end1 = clock();

    cout << "Sorted array (first element as pivot): ";
    printArray(arr1);
    double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time taken by quicksort (first element as pivot): " << time_taken1 << " seconds " << endl;

    // Sort using the random pivot implementation
    cout << "Original array: ";
    printArray(arr2);

    clock_t start2 = clock();
    quicksort(arr2, 0, n - 1);
    clock_t end2 = clock();

    cout << "Sorted array (random pivot): ";
    printArray(arr2);
    double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time taken by quicksort (random pivot): " << time_taken2 << " seconds " << endl;

    return 0;
}