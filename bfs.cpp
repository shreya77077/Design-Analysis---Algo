#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < adj[curr].size(); i++) {
            int neighbor = adj[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    cout << "BFS Traversal: ";
    BFS(adj, V, 2);
    return 0;
}
