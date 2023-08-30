#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
    double ratio; // v/w

    Item(int v, int w) : value(v), weight(w), ratio((double)v / w) {}
};

bool compareItems(const Item &item1, const Item &item2)
{
    return item1.ratio > item2.ratio;
}

class Knapsack
{
public:
    double fractionalKnapsack(int capacity, std::vector<Item> &items)
    {
        sort(items.begin(), items.end(), compareItems);
        double totalValue = 0.0;
        for (Item &item : items)
        {
            if (capacity >= item.weight)
            {
                totalValue += item.value;
                capacity -= item.weight;
            }
            else
            {
                totalValue += (capacity / (double)item.weight) * item.value;
                break;
            }
        }
        return totalValue;
    }
};

int main()
{
    cout << "Ahan Jain" << endl;
    cout << "A2305221174\n\n";

    int n;
    int capacity;

    cout << "Enter the Number of Items: ";
    cin >> n;

    cout << endl;

    vector<Item> items;

    for (int i = 0; i < n; ++i)
    {
        int value, weight;
        cout << "Enter Value and Weight of Item " << i + 1 << ": ";
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    cout << "\nEnter the Max Knapsack Capacity: ";
    cin >> capacity;

    Knapsack knapsack;
    double maxValue = knapsack.fractionalKnapsack(capacity, items);
    cout << "\nMaximum Value in the Knapsack: " << maxValue << endl;

    return 0;
}
