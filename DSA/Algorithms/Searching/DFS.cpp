#include <iostream>

using namespace std;

class Graph
{
    int vertices;
    int **adjacency;

public:
    Graph(int V)
    {
        vertices = V;
        adjacency = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adjacency[i] = new int[V];
            for (int j = 0; j < V; ++j)
            {
                adjacency[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w)
    {
        adjacency[v][w] = 1;
    }

    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; ++i)
        {
            if (adjacency[v][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startVertex)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        DFSUtil(startVertex, visited);
        delete[] visited;
    }

    ~Graph()
    {
        for (int i = 0; i < vertices; ++i)
        {
            delete[] adjacency[i];
        }
        delete[] adjacency;
    }
};

int main()

{
    cout << "Ahan Jain" << endl;
    cout << "A2305221174\n\n";

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 5);

    cout << "DFS Traversal from Vertex 0...\n\n";
    g.DFS(0);
    cout << endl;

    return 0;
}
