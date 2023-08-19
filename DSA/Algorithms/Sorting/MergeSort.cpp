#include <iostream>
using namespace std;

void Merge(int arr[], int l, int m, int h)

{
    int n1 = m - l + 1;
    int n2 = h - m;

    int i, j, k;

    // declaring two temp arrays

    int arrA[n1];
    int arrB[n2];

    // filling these two arrays

    for (i = 0; i < n1; i++)

    {
        arrA[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)

    {
        arrB[j] = arr[m + 1 + j];
    }

    // cout << "\nArray A...\n\n| ";

    // for (i = 0; i < n1; i++)

    // {
    //     cout << arrA[i] << " | ";
    // }

    // cout << "\nArray B...\n\n| ";

    // for (i = 0; i < n2; i++)

    // {
    //     cout << arrB[i] << " | ";
    // }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2)

    {
        if (arrA[i] >= arrB[j])

        {
            arr[k] = arrB[j];
            j++;
        }

        else if (arrA[i] < arrB[j])

        {
            arr[k] = arrA[i];
            i++;
        }

        k++;
    }

    while (i < n1) // Array A still has elements left

    {
        arr[k] = arrA[i];
        i++;
        k++;
    }

    while (j < n2) // Array B still has elements left

    {
        arr[k] = arrB[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int h)

{
    if (l < h) // more than one element

    {
        int mid = l + (h - l) / 2; // to prevent overflow

        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);

        Merge(arr, l, mid, h);
    }
}

int main()

{
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

    MergeSort(arr, 0, n - 1);

    cout << "\nSorted Array...\n\n| ";

    for (i = 0; i < n; i++)

    {
        cout << arr[i] << " | ";
    }

    return 0;
}