#include <iostream>
#include <algorithm>

using namespace std;

void Knapsack(int n, int M, int values[], int weights[])
{
    int dp[n + 1][M + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= M; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w - weights[i - 1]] + values[i - 1], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= M; w++)
        {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    int k = M;
    int i = n;

    while (i > 0 && k > 0)
    {
        if (dp[i][k] != dp[i - 1][k])
        {
            cout << "Item " << i << " Included.\n";
            k = k - weights[i - 1];
        }
        i--;
    }
}

int main()
{
    int v[] = {4, 8, 9, 11};
    int w[] = {2, 3, 4, 5};

    Knapsack(4, 5, v, w);

    return 0;
}
