#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> elems;
vector<vector<int>> adj;
vector<vector<int>> adj_r;
vector<int> p;
vector<bool> visited;
vector<int> comps;

void dfs(int i, int cc) {
  comps[i] = cc;
  visited[i] = true;
  for (int v : adj[i]) {
    if (!visited[v]) dfs(v, cc);
  }
}


int main() {
  int n, a, b;
  cin >> n >> a >> b;
  p = vector<int>(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    elems[p[i]] = i;
  }

  adj = vector<vector<int>>(n);
  vector<int> groups(n, 0);
  for (int i = 0; i < n; i++) {
    if (p[i] < a && elems.find(a - p[i]) != elems.end()) {
      int comp = elems[a - p[i]];
      adj[i].push_back(comp);
      adj[comp].push_back(i);
      groups[i] |= 1;
    }

    if (p[i] < b && elems.find(b - p[i]) != elems.end()) {
      int comp = elems[b - p[i]];
      adj[i].push_back(comp);
      adj[comp].push_back(i);
      groups[i] |= 2;
    }
  }

  visited = vector<bool>(n, false);
  comps = vector<int>(n, 0);
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, cc);
      cc++;
    }
  }

  vector<int> com_group(n, 3);
  bool can = true;  
  for (int i = 0; i < n; i++) {
    com_group[comps[i]] &= groups[i];
    if (com_group[comps[i]] == 0) can = false;
  }
  if (can) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (com_group[comps[i]] == 2) {
        cout << 1;
      }
      else {
        cout << 0;
      }
      cout << ' ';
    }
  }
  else {
    cout << "NO";
  }

}