// 1123534 Max Shen 12/9/24
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

// Function to create and return the adjacency list
vector<vector<int>> AdjList(int V, vector<pair<int, int>>& edges) 
{

    vector<vector<int>> adjList(V);

    for (auto edge : edges) 
    {
        int u = edge.first;  
        int v = edge.second; 

        if (find(adjList[u].begin(), adjList[u].end(), v) == adjList[u].end()) 
        {
            adjList[u].push_back(v); 
        }
        if (find(adjList[v].begin(), adjList[v].end(), u) == adjList[v].end()) 
        {
            adjList[v].push_back(u);
        }
    }

    for (int i = 0; i < V; i++) 
    {
        sort(adjList[i].begin(), adjList[i].end());
    }

    return adjList; 
}

int main()
{
    int V, E;

    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    // Input the edges
    vector<pair<int, int>> edges; 
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v; 
        edges.push_back({ u, v }); // Store the edge as a pair of nodes (u, v)
    }

    //  function to create the adjacency list
    vector<vector<int>> adjList = AdjList(V, edges);

    // Output
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) 
    {
        cout << i << ": ";
        for (int neighbor : adjList[i])
        {
            cout << neighbor << " "; 
        }
        cout << endl; 
    }

    return 0; 
