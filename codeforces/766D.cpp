#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
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
  for (int v : adj[u]) {
    if (!visited[v]) dfs2(v, cc);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }

  vector<vector<int>> room_switches(n);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      int rn;
      cin >> rn;
      rn--;
      room_switches[rn].push_back(i);
    }
  }

  adj = vector<vector<int>>(2 * m);
  for (int i = 0; i < n; i++) {
    int s1 = room_switches[i][0];
    int s2 = room_switches[i][1];
    if (r[i]) {
      adj[m + s1].push_back(m + s2);
      adj[m + s2].push_back(m + s1);
      adj[s1].push_back(s2);
      adj[s2].push_back(s1);
    }
    else {
      adj[m + s1].push_back(s2);
      adj[m + s2].push_back(s1);
      adj[s1].push_back(m + s2);
      adj[s2].push_back(m + s1);
    }
  }

  visited = vector<bool>(2 * m, false);

  for (int i = 0; i < 2 * m; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  int cc = 0;
  ccs = vector<int>(2 * m);
  visited = vector<bool>(2 * m, false);
  for (int i = order.size() - 1; i >= 0; i--) {
    int v = order[i];
    if (!visited[v]) {
      cc++;
      dfs2(v, cc);
    }
  }
  
  bool can = true;
  for (int i = 0; i < m; i++) {
    if (ccs[i] == ccs[m + i]) {
      can = false;
      break;
    }
  }

  if (can) cout << "YES";
  else cout << "NO";
}
