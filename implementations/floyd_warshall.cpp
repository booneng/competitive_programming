#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  int n_;
  vector<vector<pair<int, int>>> adj_;

public:
  Graph(int n, const vector<vector<pair<int, int>>>& adj)
      : n_(n), adj_(adj) {}

  vector<vector<int>> FloydWarshall() {
    vector<vector<int>> dists(n_, vector<int>(n_, INT_MAX));
    for (int i = 0; i < n_; i++) {
      dists[i][i] = 0;
      for (auto edge : adj_[i]) {
        int j = edge.first;
        int weight = edge.second;
        dists[i][j] = weight;
      }
    }
    for (int i = 0; i < n_; i++) {
      for (int s = 0; s < n_; s++) {
        for (int t = 0; t < n_; t++) {
          dists[s][t] = min((long long)dists[s][t], (long long)dists[s][i] + dists[i][t]);
        }
      }
    }
    return dists;
  }
};

int main() {
  int n = 10;
  vector<vector<pair<int, int>>> adj(n);
  adj[0].push_back({1, 5});
  adj[1].push_back({2, 3});
  adj[1].push_back({3, 2});
  adj[2].push_back({3, -6});
  adj[2].push_back({4, 4});
  adj[3].push_back({5, 5});
  Graph g(n, adj);
  vector<vector<int>> dists = g.FloydWarshall();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dists[i][j] << ' ';
    }
    cout << endl;
  }
}
