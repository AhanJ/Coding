#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge // Structure to represent an edge

{
    int dest, weight;
};

struct CompareEdges
{
    bool operator()(const Edge &a, const Edge &b)

    {
        return a.weight > b.weight;
    }
};

void primMinimumSpanningTree(vector<vector<Edge>> &graph, int startVertex)

{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;

    // Start with the given start vertex
    visited[startVertex] = true;

    for (const Edge &edge : graph[startVertex])

    {
        pq.push(edge);
    }

    cout << "\nMinimum Spanning Tree Edges...\n\n";

    while (!pq.empty())

    {
        Edge minEdge = pq.top();
        pq.pop();
        int dest = minEdge.dest;
        int weight = minEdge.weight;

        if (visited[dest])

        {
            continue;
        }

        cout << startVertex << " - " << dest << " : " << weight << endl;
        visited[dest] = true;

        for (const Edge &edge : graph[dest])

        {
            if (!visited[edge.dest])

            {
                pq.push(edge);
            }
        }
    }
}

int main()

{
    cout << "\nAhan Jain\nA2305221174\n";

    int numVertices,
        numEdges;

    cout << "\nEnter the Number of Vertices: ";
    cin >> numVertices;

    cout << "Enter the Number of Edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "\nEnter Edge Details (i.e. Source, Destination and Weight)...\n"
         << endl;

    for (int i = 0; i < numEdges; ++i)

    {
        int src, dest, weight;
        cout << "Edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }

    int startVertex;
    cout << "\nEnter the Start Vertex: ";
    cin >> startVertex;
    primMinimumSpanningTree(graph, startVertex);
    cout << endl;
    return 0;
}
