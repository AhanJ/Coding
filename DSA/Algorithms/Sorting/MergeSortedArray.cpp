#include <iostream>
using namespace std;

int main()

{
    int m, n, i, j, k;

    cout << "Enter Size of Array A: ";
    cin >> m;

    cout << endl;

    int arrA[m];

    for (i = 0; i < m; i++) // getting elements of Array A

    {
        cout << "Enter Element " << i << " of " << m - 1 << ": ";
        cin >> arrA[i];
    }

    sort(arrA, arrA + m); // sort Array A

    cout << "\nEnter Size of Array B: ";
    cin >> n;

    cout << endl;

    int arrB[n];

    for (i = 0; i < n; i++) // getting elements of Array B

    {
        cout << "Enter Element " << i << " of " << n - 1 << ": ";
        cin >> arrB[i];
    }

    sort(arrB, arrB + n); // sort Array B

    int arrC[m + n];

    i = j = k = 0;

    while (i < m && j < n)

    {
        if (arrA[i] >= arrB[j])

        {
            arrC[k] = arrB[j];
            j++;
        }

        else if (arrA[i] < arrB[j])

        {
            arrC[k] = arrA[i];
            i++;
        }

        k++;
    }

    while (i < m) // Array A still has elements left

    {
        arrC[k] = arrA[i];
        i++;
        k++;
    }

    while (j < n) // Array B still has elements left

    {
        arrC[k] = arrB[j];
        j++;
        k++;
    }

    cout << "\nMerged Sorted Array...\n\n| ";

    for (i = 0; i < m + n; i++)

    {
        cout << arrC[i] << " | ";
    }

    return 0;
}