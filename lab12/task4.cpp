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

// Insertion Sort implementation
void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to select a random pivot and partition the array
int partitionRandomPivot(vector<int> &arr, int low, int high)
{
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
    swap(arr[low], arr[i - 1]);
    return i - 1; // Return the index of the pivot
}

// Quick Sort with Insertion Sort fallback
void quicksortRandomPivot(vector<int> &arr, int low, int high)
{
    if (high - low < 10)
    { // Use Insertion Sort for small subarrays
        insertionSort(arr, low, high);
    }
    else
    {
        if (low < high)
        {
            int pivotIndex = partitionRandomPivot(arr, low, high);
            quicksortRandomPivot(arr, low, pivotIndex - 1);
            quicksortRandomPivot(arr, pivotIndex + 1, high);
        }
    }
}

vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
    return arr;
}

void measurePerformance(int size)
{
    vector<int> arr1 = generateRandomArray(size);
    vector<int> arr2 = arr1; // Copy for comparison

    // Measure time for quicksort with Insertion Sort fallback
    clock_t start = clock();
    quicksortRandomPivot(arr1, 0, size - 1);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Array size: " << size << endl;
    cout << "Time taken by quicksort with Insertion Sort fallback: " << time_taken << " seconds" << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Measure performance for different sizes
    measurePerformance(100);
    measurePerformance(1000);
    measurePerformance(10000);

    return 0;
}