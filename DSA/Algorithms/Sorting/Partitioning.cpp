#include <iostream>
#include <algorithm>

using namespace std;

int main()

{
    int n, i, j;

    cout << "Enter Size of the Array: ";
    cin >> n;

    cout << endl;

    int arrA[n];

    for (i = 0; i < n; i++)

    {
        cout << "Enter Element " << i << " of " << n - 1 << ": ";
        cin >> arrA[i];
    }

    int pivot = arrA[0];
    int temp;

    i = 0;
    j = n - 1;

    while (i <= j)

    {
        while (arrA[i] <= pivot)

        {
            i++;
        }

        while (arrA[j] > pivot)

        {
            j--;
        }

        if (i <= j)

        {
            swap(arrA[i], arrA[j]);
            i++;
            j--;
        }
    }

    swap(arrA[j], arrA[0]);

    cout << "\nPartitioned Array...\n\n| ";

    for (i = 0; i < n; i++)

    {
        cout << arrA[i] << " | ";
    }

    return 0;
}