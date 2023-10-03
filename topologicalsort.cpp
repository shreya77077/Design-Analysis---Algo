#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFSUtil(vector<int> adj[], int v, vector<bool>& visited, stack<int>& stk) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor])
            DFSUtil(adj, neighbor, visited, stk);
    }
    stk.push(v);
}

void topologicalSort(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    stack<int> stk;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(adj, i, visited, stk);
    }
    cout << "Topological Sorting: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main() {
    int V = 6;
    vector<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    cout << "Number of vertices: " << V << endl;
    topologicalSort(adj, V);
    return 0;
}
