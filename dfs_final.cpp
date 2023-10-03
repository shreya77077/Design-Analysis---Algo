#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(vector<int> adj[], int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < adj[v].size(); i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor])
            DFSUtil(adj, neighbor, visited);
    }
}

void DFS(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    DFSUtil(adj, start, visited);
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    cout << "DFS Traversal: ";
    DFS(adj, V, 2);
    return 0;
}
