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

    for (int i = 0; i < list.size(); i++)

    {
        cout << list[i];
    }

    return 0;
}