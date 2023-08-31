#include <iostream>
using namespace std;

int main()

{
    int u, v;

    cout << "Enter the Number of Nodes: ";
    cin >> u;

    cout << "Enter the Number of Edges: ";
    cin >> v;

    cout << endl;

    int adj[u + 1][u + 1]; // initialsing a 2D matrix assuming nodes have base 1 i.e. start from 1 (1,2,3...)

    for (int i = 0; i < v; i++) // i < v i.e. number of edges because number of edges represent number of connections so basically that's the number of times we should be running this loop

    {
        int u1, u2;

        cout << "Enter the Nodes for Connecting (Separated by a Space): ";
        cin >> u1 >> u2;

        adj[u1][u2] = 1; // for weighted graph adj[u1][u2] = <edge weight>
        adj[u2][u1] = 1; // not necessary for directed graph
    }

    return 0;
}