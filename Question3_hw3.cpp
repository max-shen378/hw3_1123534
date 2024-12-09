// 1123534 Max Shen 12/9/24
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// function to perform DFS recursively
void dfs(int node, const vector<vector<int>>& adj, unordered_set<int>& visited, vector<int>& result) 
{
    visited.insert(node);
    result.push_back(node);

    for (int neighbor : adj[node]) 
    {
        if (visited.find(neighbor) == visited.end()) 
        {
            dfs(neighbor, adj, visited, result); 
        }
    }
}

// Function to perform DFS traversal starting from vertex 0
vector<int> dfsTraversal(const vector<vector<int>>& adj) {
    vector<int> result;            // store the DFS traversal result
    unordered_set<int> visited;   
    dfs(0, adj, visited, result);

    return result;
}

int main() 
{
    // Input 
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> adj(n);

    cout << "Enter the adjacency list (enter neighbors for each vertex):" << endl;
    for (int i = 0; i < n; ++i) 
    {
        cout << "Vertex " << i << ": ";
        int num_neighbors;
        cin >> num_neighbors;
        adj[i].resize(num_neighbors);

        for (int j = 0; j < num_neighbors; ++j) 
        {
            cin >> adj[i][j];  
        }
    }

    // Perform DFS traversal
    vector<int> result = dfsTraversal(adj);

    // Output
    cout << "DFS Traversal Result: ";
    for (int v : result) 
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
