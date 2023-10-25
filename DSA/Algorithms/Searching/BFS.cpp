#include <iostream>
#include <queue>
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

    void BFS(int startVertex)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        queue<int> bfsQueue;
        bfsQueue.push(startVertex);
        visited[startVertex] = true;

        while (!bfsQueue.empty())
        {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            cout << currentVertex << " ";

            for (int i = 0; i < vertices; ++i)
            {
                if (adjacency[currentVertex][i] == 1 && !visited[i])
                {
                    bfsQueue.push(i);
                    visited[i] = true;
                }
            }
        }

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

    cout << "BFS Traversal from Vertex 0...\n\n";
    g.BFS(0);
    cout << endl;

    return 0;
}
