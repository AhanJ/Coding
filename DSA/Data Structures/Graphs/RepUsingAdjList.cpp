#include <iostream>
#include <vector>
using namespace std;

int main()

{
    int u, v;

    cout << "Enter the Number of Nodes: ";
    cin >> u;

    cout << "Enter the Number of Edges: ";
    cin >> v;

    cout << endl;

    vector<int> adj[u + 1]; // to initialise an array we use '<datatype> arr[size]'. What this does is create an array which can store data of type specified. Here what we do is create an array of size one greater than the number of nodes we have (assuming nodes start from 1 i.e. base 1) and each cell in this array stores a vector of type 'int'. We create an array of integer vectors. This is essentially the implementation of a list.

    for (int i = 0; i < v; i++) // i < number of edges because number of edges represent number of connections

    {
        int u1, u2;

        cout << "Enter the Nodes for Connecting (Separated by a Space): ";
        cin >> u1 >> u2;

        adj[u1].push_back(u2); // push u2 in the vector at index u1
        adj[u2].push_back(u1); // push u1 in the vector at index u2, not necessary for directed graph
    }

    return 0;
}