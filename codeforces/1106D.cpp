#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> order;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    visited[1] = true;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        order.push_back(cur);
        for (int j : adj[cur]) {
            if (!visited[j]) {
                pq.push(j);
                visited[j] = true;
            }
        }
    }
    for (int i : order) cout << i << ' ';
}