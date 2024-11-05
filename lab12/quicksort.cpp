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
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
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
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    int n = arr.size();
    cout << "original array :";
    printArray(arr);

    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "sorted array :";
    printArray(arr);
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "tim taken by quicksort: " << time_taken << " seconds " << endl;
    return 0;
}