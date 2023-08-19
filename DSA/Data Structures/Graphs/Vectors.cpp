#include <iostream>
#include <vector>
using namespace std;

int main()

{
    vector<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    for (int i = 0; i < list.size(); i++)

    {
        cout << list[i];
    }

    cout << endl;

    for (auto i : list)

    {
        cout << i;
    }

    return 0;
}