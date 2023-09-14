#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();
int minDistance(const vector<int> &dist, const vector<bool> &sptSet, int V)
{
    int minDist = INF, minIndex = -1;
    for (int v = 0; v < V; ++v)
    {
        if (!sptSet[v] && dist[v] <= minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void printSolution(const vector<int> &dist, int V, int src)
{
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << " \t\t " << dist[i] << endl;
    }
}
void printShortestPath(const vector<int> &parent, int j)
{
    if (parent[j] == -1)
    {
        cout << j;
        return;
    }
    printShortestPath(parent, parent[j]);
    cout << " -> " << j;
}
void dijkstra(vector<vector<int>> &graph, int src, int target)
{
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> sptSet(V, false);
    vector<int> parent(V, -1);
    dist[src] = 0;
    for (int count = 0; count < V - 1; ++count)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; ++v)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(dist, V, src);
    cout << "Shortest path from " << src << " to " << target << ": ";
    printShortestPath(parent, target);
    cout << endl;
}
int main()
{
    int V, E, src, target;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges and their weights (source, destination, weight):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Assuming an undirected graph
    }
    cout << "Enter the source vertex: ";
    cin >> src;

    // cout << "Enter the target vertex: ";
    // cin >> target;

        dijkstra(graph, src, target);
    return 0;
}