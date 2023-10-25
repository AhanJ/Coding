#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item
{
    int value;
    int weight;
};

// Function to solve the 0/1 Knapsack problem using backtracking
void knapsackBacktracking(vector<Item> &items, int capacity, int &maxProfit, vector<int> &selectedItems, vector<int> &currentItems, int currentWeight, int currentValue, int index)
{
    if (index == items.size())
    {
        if (currentValue > maxProfit)
        {
            maxProfit = currentValue;
            selectedItems = currentItems;
        }
        return;
    }

    if (currentWeight + items[index].weight <= capacity)
    {
        currentItems[index] = 1;
        knapsackBacktracking(items, capacity, maxProfit, selectedItems, currentItems, currentWeight + items[index].weight, currentValue + items[index].value, index + 1);
        currentItems[index] = 0;
    }

    knapsackBacktracking(items, capacity, maxProfit, selectedItems, currentItems, currentWeight, currentValue, index + 1);
}

int main()
{
    cout << "\nAhan Jain\nA2305221174\n\n";

    int n; // Number of items
    cout << "Enter the Number of Items: ";
    cin >> n;
    cout << endl;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value and Weight for Item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "\nEnter the Knapsack Capacity: ";
    cin >> capacity;

    int maxProfit = 0;
    vector<int> selectedItems(n, 0);
    vector<int> currentItems(n, 0);

    knapsackBacktracking(items, capacity, maxProfit, selectedItems, currentItems, 0, 0, 0);

    cout << "\nSelected Items for Maximum Profit...\n\n";
    for (int i = 0; i < n; i++)
    {
        if (selectedItems[i])
            cout << "Item " << i + 1 << " ";
    }

    cout << "\n\nTotal Profit: " << maxProfit << endl;

    return 0;
}
