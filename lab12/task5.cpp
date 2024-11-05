#include <iostream>
#include <vector>
using namespace std;
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
    int i = 0;    
    int j = 0;    
    int k = left; 
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

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test Merge Sort
int main()
{
    // Test arrays
    vector<vector<int>> testArrays = {
        {38, 27, 43, 3, 9, 82, 10},
        {5, 1, 4, 2, 8},
        {12, 11, 13, 5, 6, 7},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {15, 5, 20, 10, 30, 25}};

    // Sort and print each test array
    for (auto &arr : testArrays)
    {
        cout << "Original array: ";
        printArray(arr);

        mergeSort(arr, 0, arr.size() - 1);

        cout << "Sorted array: ";
        printArray(arr);
        cout << "-----------------------------------" << endl;
    }

    return 0;
}