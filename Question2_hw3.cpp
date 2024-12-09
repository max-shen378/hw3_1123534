// 1123534 Max Shen 12/9/24
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& adj, int start = 0)
{
    vector<int> result;
    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);

    // Process queue
    while (!q.empty()) 
    {
        int node = q.front();  
        q.pop();                
        result.push_back(node); 

        for (int neighbor : adj[node]) 
        {
            if (visited.find(neighbor) == visited.end())
            { 
                visited.insert(neighbor); 
                q.push(neighbor);         
            }
        }
    }

    return result;
}

int main() 
{
    //Input 
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> adj(n);

    cout << "Enter the adjacency list:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        int num_neighbors;
        cin >> num_neighbors;
        adj[i].resize(num_neighbors);
        for (int j = 0; j < num_neighbors; ++j) 
        {
            cin >> adj[i][j];  // Read each neighbor of vertex i
        }
    }
    // Perform BFS starting from vertex 0
    vector<int> result = bfsTraversal(adj);

    //Output
    cout << "BFS Traversal Result: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
