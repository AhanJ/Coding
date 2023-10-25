#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const int N = 10; // Maximum number of cities
int final_path[N + 1];
bool visited[N];
int final_res = INT_MAX;

void copyToFinal(int curr_path[], int n)
{
    for (int i = 0; i < n; i++)
        final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
}

int firstMin(int adj[N][N], int i, int n)
{
    int min = INT_MAX;
    for (int k = 0; k < n; k++)
        if (adj[i][k] < min && i != k)
            min = adj[i][k];
    return min;
}

int secondMin(int adj[N][N], int i, int n)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (i == j)
            continue;
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void TSPRec(int adj[N][N], int curr_bound, int curr_weight, int level, int curr_path[], int n)
{
    if (level == n)
    {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if (curr_res < final_res)
            {
                copyToFinal(curr_path, n);
                final_res = curr_res;
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (adj[curr_path[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];
            if (level == 1)
                curr_bound -= ((firstMin(adj, curr_path[level - 1], n) + firstMin(adj, i, n)) / 2);
            else
                curr_bound -= ((secondMin(adj, curr_path[level - 1], n) + firstMin(adj, i, n)) / 2);
            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path, n);
            }
            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP(int adj[N][N], int n)
{
    int curr_path[N + 1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
        curr_bound += (firstMin(adj, i, n) + secondMin(adj, i, n));
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;
    visited[0] = true;
    curr_path[0] = 0;
    TSPRec(adj, curr_bound, 0, 1, curr_path, n);
}

int main()

{
    cout << "\nAhan Jain\nA2305221174\n";

    int n;
    cout << "\nEnter the Number of Cities (Max " << N << "): ";
    cin >> n;
    if (n <= 2 || n > N)
    {
        cout << "Invalid number of cities. Please enter a value between 3 and " << N << "." << endl;
        return 1;
    }
    int adj[N][N]; // Adjacency matrix for the given graph
    cout << "\nEnter the Distance Matrix...\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    TSP(adj, n);
    cout << "\nCost of Minimum Path: " << final_res << endl;
    cout << "\nPath Taken: ";
    for (int i = 0; i <= n; i++)
    {
        cout << final_path[i] + 1 << " ";
        if (i < n)
            cout << "-> ";
    }
    cout << endl
         << endl;
    return 0;
}