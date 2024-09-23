#include<iostream>
using namespace std;
int binarysearch(int arr[],int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid =(low+high)/2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;

        }
    }
    return -1;
}
int main()
{
    int arr[10];
    int size;
    cout << "Enter the size of array:" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at index:" << endl;
        cin >> arr[i];
    }
    size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "enter the value to be serach:" << endl;
    cin >> target;
    int result = binarysearch(arr, size, target);
    if (result == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index:" << result << endl;
    }
    return 0;
}