#include <iostream>
#include <vector>

using namespace std;

int n;               // Number of items
vector<int> values;  // Array to store values of items
vector<int> weights; // Array to store weights of items
vector<int> vsol;    // Stores the selected items
int solution = 0;    // Maximum value
bool issol = false;  // Indicates if a solution exists

void Knapsack(int i, int max, int value)
{
    vector<int> temp; // Temporary vector to store the current combination of items

    for (int k = i; k < n; k++)
    {
        if (max > 0)
        {
            if (weights[k] <= max)
            {
                temp.push_back(k);
                if (value + values[k] >= solution)
                {
                    solution = value + values[k];
                    issol = true;
                }
            }
            if ((k + 1) < n)
            {
                Knapsack(k + 1, max - weights[k], value + values[k]);
            }
            else
            {
                if (issol == true)
                {
                    if (!vsol.empty())
                        vsol.clear();
                    std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
                    temp.clear();
                    issol = false;
                }
                else
                {
                    temp.clear();
                }
                return;
            }
        }
        else
        {
            if (issol == true)
            {
                if (!vsol.empty())
                    vsol.clear();
                std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
                temp.clear();
                issol = false;
            }
            else
            {
                temp.clear();
            }
            return;
        }
    }
}

int main()
{
    int maxWeight;

    // Input the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    values.resize(n);
    weights.resize(n);

    // Input the values and weights of the items
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the value and weight of item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }

    // Input the maximum weight capacity of the knapsack
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    Knapsack(0, maxWeight, 0);

    cout << "Selected items to maximize value:" << endl;
    for (int idx : vsol)
    {
        cout << "Value: " << values[idx] << ", Weight: " << weights[idx] << endl;
    }

    cout << "Total value: " << solution << endl;
    return 0;
}
