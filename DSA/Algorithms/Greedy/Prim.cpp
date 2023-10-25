#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])

{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])

{
    cout << "\nEdge \tWeight\n\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])

{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)

    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main()

{
    cout << "\nAhan Jain\nA2305221174\n";

    int graph[V][V] = {
        {0, 2, 0, 5, 0},
        {2, 0, 1, 3, 3},
        {0, 1, 0, 0, 4},
        {5, 3, 0, 0, 3},
        {0, 3, 4, 3, 0}};

    primMST(graph);

    cout << endl;

    return 0;
}
