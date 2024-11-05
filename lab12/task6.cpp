#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

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

int partitionRandomPivot(vector<int> &arr, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[low]);
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
    return i - 1;
}

void quicksortRandomPivot(vector<int> &arr, int low, int high)
{
    if (high - low < 10)
    {
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

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000;
    }
    return arr;
}

void measurePerformance(int size)
{
    vector<int> arr1 = generateRandomArray(size);
    vector<int> arr2 = arr1;

    clock_t startQuick = clock();
    quicksortRandomPivot(arr1, 0, size - 1);
    clock_t endQuick = clock();
    double timeQuick = double(endQuick - startQuick) / CLOCKS_PER_SEC;

    clock_t startMerge = clock();
    mergeSort(arr2, 0, size - 1);
    clock_t endMerge = clock();
    double timeMerge = double(endMerge - startMerge) / CLOCKS_PER_SEC;

    cout << "Performance for array size " << size << ":\n";
    cout << "Quick Sort time: " << timeQuick << " seconds\n";
    cout << "Merge Sort time: " << timeMerge << " seconds\n";
    cout << "-----------------------------------" << endl;
}

int main()
{
    srand(time(0));

    for (int size : {1000, 5000, 10000, 50000, 100000})
    {
        measurePerformance(size);
    }

    return 0;
}