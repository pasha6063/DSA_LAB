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
int partitionRandomPivot(vector<int> &arr, int low, int high)
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

// Function to partition using the first element as pivot
int partitionFirstElement(vector<int> &arr, int low, int high)
{
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

void quicksortRandomPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionRandomPivot(arr, low, high);
        quicksortRandomPivot(arr, low, pivotIndex - 1);
        quicksortRandomPivot(arr, pivotIndex + 1, high);
    }
}

void quicksortFirstElement(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionFirstElement(arr, low, high);
        quicksortFirstElement(arr, low, pivotIndex - 1);
        quicksortFirstElement(arr, pivotIndex + 1, high);
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

    // Measure time for quicksort with first element as pivot
    clock_t start1 = clock();
    quicksortFirstElement(arr1, 0, size - 1);
    clock_t end1 = clock();
    double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;

    // Measure time for quicksort with random pivot
    clock_t start2 = clock();
    quicksortRandomPivot(arr2, 0, size - 1);
    clock_t end2 = clock();
    double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;

    cout << "Array size: " << size << endl;
    cout << "Time taken by quicksort (first element as pivot): " << time_taken1 << " seconds" << endl;
    cout << "Time taken by quicksort (random pivot): " << time_taken2 << " seconds" << endl;
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
