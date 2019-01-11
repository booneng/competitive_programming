#include <bits/stdc++.h>

using namespace std;

class FlowGraph {
private:
  int s_;
  int t_;
  int n_;
  vector<vector<int>> adj_;
  vector<vector<int>> edge_weights_;

public:

  FlowGraph(int n, int s, int t, vector<vector<int>>& adj, vector<vector<int>>& edge_weights)
      : n_(n),
        s_(s),
        t_(t),
        adj_(adj),
        edge_weights_(edge_weights) {
    for (int i = 0; i < edge_weights_.size(); i++) {
      for (int j : edge_weights_[i]) cout << j << ' ';
      cout << endl;
    }
  }

  int BFS() {
    vector<int> path(n_, -1);
    path[s_] = s_;
    queue<int> q;
    q.push(s_);
    bool can = false;
    while (!q.empty()) {
      int prev = q.front();
      q.pop();
      if (prev == t_) {
        can = true;
        break;
      }
      for (int next : adj_[prev]) {
        if (edge_weights_[prev][next] == 0 || path[next] != -1) continue;
        path[next] = prev;
        q.push(next);
      }
    }

    if (!can) return 0;
    int cur = t_;
    int min_capacity = INT_MAX;
    while (cur != s_) {
      int prev = path[cur];
      min_capacity = min(edge_weights_[prev][cur], min_capacity);
      cur = prev;
    }

    cur = t_;
    // update edge_weights
    while (cur != s_) {
      int prev = path[cur];
      edge_weights_[prev][cur] -= min_capacity;
      edge_weights_[cur][prev] += min_capacity;
      cur = prev;
    }

    return min_capacity;
  }

  int EdmondKarp() {
    int res = 0;
    int flow = BFS();
    while (flow) {
      res += flow;
      flow = BFS();
    }
    return res;
  }

};

FlowGraph CreateFlowGraph(
    int n,
    int s,
    int t,
    vector<vector<int>>& capacities,
    vector<vector<int>>& demands,
    vector<vector<int>>& adj) {
  // create new graph for max flow
  int np = n + 2;
  int sp = n;
  int tp = n + 1;
  vector<vector<int>> fadj(np);
  vector<vector<int>> weights(np, vector<int>(np, 0));
  int demand_sum = 0;
  for (int i = 0; i < n; i++) {
    fadj[i] = adj[i];
    for (int j : adj[i]) {
      if (capacities[i][j] > 0) {
        weights[i][j] = capacities[i][j] - demands[i][j];
        demand_sum += demands[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      weights[i][tp] += demands[i][j];
      weights[sp][j] += demands[i][j];
    }
    fadj[sp].push_back(i);
    fadj[i].push_back(sp);
    fadj[tp].push_back(i);
    fadj[i].push_back(tp);
  }
  weights[t][s] = INT_MAX;
  fadj[s].push_back(t);
  fadj[t].push_back(s);


  FlowGraph fg(np, sp, tp, fadj, weights);
  return fg;
}


int main() {
  int n = 4;
  int t = 3;
  int s = 0;

  vector<vector<int>> capacities(n, vector<int>(n));
  vector<vector<int>> demands(n, vector<int>(n));
  vector<vector<int>> adj(n);

  adj[0].push_back(1);
  capacities[0][1] = 10;
  demands[0][1] = 3;
  adj[0].push_back(2);
  capacities[0][2] = 8;
  demands[0][2] = 4;
  adj[1].push_back(2);
  capacities[1][2] = 5;
  demands[1][2] = 1;
  adj[1].push_back(3);
  capacities[1][3] = 8;
  demands[1][3] = 7;
  adj[2].push_back(3);
  capacities[2][3] = 6;
  demands[2][3] = 2;
  FlowGraph fg = CreateFlowGraph(n, t, s, capacities, demands, adj);
  cout << fg.EdmondKarp();

}