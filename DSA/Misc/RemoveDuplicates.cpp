#include <iostream>
using namespace std;

int main()

{
    int n, i, j, k = 0, flag = 0;

    cout << "Enter Size of the Array: ";
    cin >> n;

    cout << endl;

    int arrA[n]; // original array
    int arrB[n]; // array with unique elements

    for (i = 0; i < n; i++)

    {
        cout << "Enter Element " << i << " of " << n - 1 << ": ";
        cin >> arrA[i];
    }

    for (i = 0; i < n; i++)

    {
        flag = 0;

        for (j = 0; j < n; j++)

        {
            if (arrA[i] == arrB[j])

            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)

        {
            arrB[k] = arrA[i];
            k++;
        }
    }

    cout << "\nUnique Array...\n\n| ";

    for (i = 0; i < k; i++)

    {
        cout << arrB[i] << " | ";
    }

    return 0;
}