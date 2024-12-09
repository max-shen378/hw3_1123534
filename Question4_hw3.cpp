// 1123534 Max Shen 12/9/24
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int Algorithm(int V, vector<vector<pair<int, int>>>& adj) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store the minimum edge weight for each vertex
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    // Start with vertex 0
    pq.push({ 0, 0 }); 
    key[0] = 0;

    int mst_weight = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mst_weight += key[u];

        for (const auto& neighbor : adj[u]) 
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) 
            {
                key[v] = weight;
                pq.push({ key[v], v });
            }
        }
    }

    return mst_weight;
}

int main() 
{
    // Input 
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < E; ++i) 
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({ v, weight });
        adj[v].push_back({ u, weight }); 
    }

    // Run Algorithm to find the MST weight sum
    int mst_weight = Algorithm(V, adj);

    //Output
    cout << "Weight of the Minimum Spanning Tree: " << mst_weight << endl;

    return 0;
}
