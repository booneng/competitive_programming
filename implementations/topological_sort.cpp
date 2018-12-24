#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adj_r;
vector<int> order;
vector<bool> visited;
vector<int> ccs;

void dfs(int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) dfs(v);
  }
  order.push_back(u);
}

void dfs2(int u, const int cc) {
  visited[u] = true;
  ccs[u] = cc;
  for (int v : adj_r[u]) {
    if (!visited[v]) dfs2(v, cc);
  }
}


int main() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  adj_r = vector<vector<int>>(n);
  for (int i = 0; i < m; i++) {
    int v, w;
    cin >> v >> w;
    adj[v].push_back(w);
    adj_r[w].push_back(v);
  }

  visited = vector<bool>(n, false);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  int cc = 0;
  ccs = vector<int>(n);
  visited = vector<bool>(n, false);
  for (int i = order.size() - 1; i >= 0; i--) {
    int v = order[i];
    if (!visited[v]) {
      cc++;
      dfs2(v, cc);
    }
  }
  
  for (int i : ccs) {
    cout << i << ' ';
  }
}