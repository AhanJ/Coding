#include <iostream>
#include <algorithm>

using namespace std;

int Partition(int arr[], int l, int h)

{
    // cout << endl;

    // for (int i = 0; i < 8; i++)

    // {
    //     cout << arr[i] << " | ";
    // }

    // cout << endl;

    int pivot = arr[l];
    int pivpos = l;

    while (l <= h)

    {
        while (arr[l] <= pivot)

        {
            l++;
        }

        while (arr[h] > pivot)

        {
            h--;
        }

        if (l <= h)

        {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
    }

    swap(arr[pivpos], arr[h]);

    // cout << endl;

    // for (int i = l; i <= h; i++)

    // {
    //     cout << arr[i] << " | ";
    // }

    // cout << endl;

    return h;
}

void QuickSort(int arr[], int l, int h)

{
    // cout << endl;

    // for (int i = 0; i < 8; i++)

    // {
    //     cout << arr[i] << " | ";
    // }

    // cout << endl;

    if (l < h) // making sure there are at least 2 elements in the array

    {
        int pos = Partition(arr, l, h); // getting position of pivot
        QuickSort(arr, l, pos - 1);     // QuickSort on left sub-array
        QuickSort(arr, pos + 1, h);     // QuickSort on right sub-array
    }
}

int main()

{
    cout << "Ahan Jain\nA2305221174\n";

    int n, i;

    cout << "Enter Size of the Array: ";
    cin >> n;

    cout << endl;

    int arr[n];

    for (i = 0; i < n; i++)

    {
        cout << "Enter Element " << i << " of " << n - 1 << ": ";
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    cout << "\nSorted Array...\n\n| ";

    for (i = 0; i < n; i++)

    {
        cout << arr[i] << " | ";
    }

    return 0;
}