#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Comparator function for sorting edges based on their weights
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

class DisjointSet
{
public:
    DisjointSet(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

vector<Edge> kruskalMinimumSpanningTree(vector<Edge> &edges, int numVertices)
{
    vector<Edge> mst; // Minimum Spanning Tree
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(numVertices);

    for (const Edge &edge : edges)
    {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        if (srcRoot != destRoot)
        {
            mst.push_back(edge);
            ds.unite(srcRoot, destRoot);
        }
    }

    return mst;
}

int main()

{
    cout << "\nAhan Jain\nA2305221174\n";

    cout << "\nEnter the Number of Vertices and Edges: ";
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "\nEnter Edge Details (i.e. Source, Destination and Weight)...\n\n";

    for (int i = 0; i < numEdges; ++i)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMinimumSpanningTree(edges, numVertices);

    cout << "\nMinimum Spanning Tree Edges...\n"
         << endl;

    for (const Edge &edge : mst)

    {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}