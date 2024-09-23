#include <iostream>
using namespace std;
int linearsearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
  
    int arr[6];
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
    int result = linearsearch(arr, size, target);
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
