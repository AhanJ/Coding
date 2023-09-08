#include <iostream>
using namespace std;

int main()

{
    int n;
    int arr[n];

    cin >> n; // getting the number of elements in the array

    for (int i = 0; i < n; i++) // entering the array elements

    {
        cin >> arr[i];
    }

    int hash[n + 1];

    for (int i = 0; i < n; i++)

    {
        hash[arr[i]]++;
    }

    return 0;
}