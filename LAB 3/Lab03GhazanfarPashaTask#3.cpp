#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
        {
            return m;
        }
        else if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    srand(time(0)); // seed for random number generation

    int sizes[] = {100, 1000, 10000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++)
    {
        int n = sizes[i];
        int *arr = new int[n]; // dynamic memory allocation

        // Generate random integers
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % 100000; // random integers between 0 and 100000
        }

        // Sort the array for binary search
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[j] > arr[k])
                {
                    swap(arr[j], arr[k]);
                }
            }
        }

        int x = rand() % 100000; // random search element

        clock_t start, end;

        // Measure time for linear search
        start = clock();
        linearSearch(arr, n, x);
        end = clock();
        double linearTime = double(end - start) / CLOCKS_PER_SEC;

        // Measure time for binary search
        start = clock();
        binarySearch(arr, 0, n - 1, x);
        end = clock();
        double binaryTime = double(end - start) / CLOCKS_PER_SEC;

        cout << "Array Size: " << n << endl;
        cout << "Linear Search Time: " << linearTime << " seconds" << endl;
        cout << "Binary Search Time: " << binaryTime << " seconds" << endl;
        cout << endl;

        delete[] arr; // free the dynamically allocated memory
    }

    return 0;
}