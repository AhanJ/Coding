#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int arr[], int l, int h, int key)

{
    if (l == h)

    {
        if (arr[l] == key)

        {
            return l;
        }

        else

        {
            return -1;
        }
    }

    int mid = l + (h - l) / 2; // to prevent overflow

    if (arr[mid] == key)

    {
        return mid;
    }

    else if (arr[mid] < key)

    {
        return BinarySearch(arr, mid + 1, h, key);
    }

    else

    {
        return BinarySearch(arr, l, mid - 1, key);
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

    sort(arr, arr + n);

    cout << "\nSorted Array...\n\n| ";

    for (i = 0; i < n; i++)

    {
        cout << arr[i] << " | ";
    }

    cout << endl;

    int key;

    cout << endl;

    cout << "Enter Element to be Found: ";
    cin >> key;

    cout << endl;

    int res = BinarySearch(arr, 0, n - 1, key);

    if (res != -1)

    {
        cout << "Element Found at Index " << res << endl;
    }

    else

    {
        cout << "Element Not Found" << endl;
    }

    return 0;
}