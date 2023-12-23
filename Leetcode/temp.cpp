#include <iostream>
#include <algorithm>
using namespace std;

int main()

{
    int demo[10] = {1, 2, 3, 4, 5, 3, 1, 8, 7, 4};

    sort(begin(demo), end(demo));

    for (auto &i : demo)

    {
        cout << i;
    }

    return 0;
}