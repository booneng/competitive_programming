#include <bits/stdc++.h>

using namespace std;

const int n = 8;
const int t = 7;
const int s = 0;

int edge_weights[n][n];
vector<int> adj[n];

int BFS() {
  vector<int> path(n, -1);
  path[s] = s;
  queue<int> q;
  q.push(s);
  bool can = false;
  while (!q.empty()) {
    int prev = q.front();
    q.pop();
    for (int next : adj[prev]) {
      if (edge_weights[prev][next] == 0 || path[next] != -1) continue;
      path[next] = prev;
      if (next == t) {
        can = true;
        break;
      }
      q.push(next);
    }
  }
  
  if (!can) return false;
  int cur = t;
  int min_capacity = INT_MAX;

  while (cur != s) {
    int prev = path[cur];
    min_capacity = min(min_capacity, edge_weights[prev][cur]);
    cur = prev;
  }

  cur = t;
  while (cur != s) {
    int prev = path[cur];
    edge_weights[prev][cur] -= min_capacity;
    edge_weights[cur][prev] += min_capacity;
    cur = prev;
  }
  return min_capacity;
}

int EdmondKarp() {
  int flow = 0;
  int cur_flow = BFS();
  while (cur_flow) {
    flow += cur_flow;
    cur_flow = BFS();
  }
  return flow;
}



int main() {

  adj[0].push_back(1);
  adj[1].push_back(0);
  edge_weights[0][1] = 6;
  adj[0].push_back(2);
  adj[2].push_back(0);
  edge_weights[0][2] = 4;
  adj[0].push_back(3);
  adj[3].push_back(0);
  edge_weights[0][3] = 5;
  adj[1].push_back(4);
  adj[4].push_back(1);
  edge_weights[1][4] = 8;
  adj[1].push_back(5);
  adj[5].push_back(1);
  edge_weights[1][5] = 2;
  adj[2].push_back(5);
  adj[5].push_back(2);
  edge_weights[2][5] = 1;
  adj[3].push_back(6);
  adj[6].push_back(3);
  edge_weights[3][6] = 8;
  adj[4].push_back(3);
  adj[3].push_back(4);
  edge_weights[4][3] = 2;
  adj[4].push_back(7);
  adj[7].push_back(4);
  edge_weights[4][7] = 5;
  adj[5].push_back(4);
  adj[4].push_back(5);
  edge_weights[5][4] = 2;
  adj[6].push_back(5);
  adj[5].push_back(6);
  edge_weights[6][5] = 3;
  adj[6].push_back(7);
  adj[7].push_back(6);
  edge_weights[6][7] = 7;

  int original[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      original[i][j] = edge_weights[i][j];
    }
  }

  cout << EdmondKarp() << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (original[i][j]) {
        cout << i << "-->" << j << ": " << edge_weights[j][i] << endl;
      }
    }
  }
}