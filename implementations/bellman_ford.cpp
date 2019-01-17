#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
  int n_;
  int source_;
  vector<vector<pair<int, int>>> adj_;

public:
  Graph(int n, int source, const vector<vector<pair<int, int>>>& adj)
      : n_(n), source_(source), adj_(adj) {}

  vector<int> BellmanFord() {
    vector<int> dists(n_, INT_MAX);
    dists[source_] = 0;
    for (int i = 0; i < n_; i++) {
      for (int from = 0; from < n_; from++) {
        if (dists[from] == -1) continue;
        for (auto edge : adj_[from]) {
          int to = edge.first;
          int weight = edge.second;
          if (dists[to] > (long long)dists[from] + weight) {
            dists[to] = dists[from] + weight;
          }
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
  int source = 0;
  Graph g(n, source, adj);
  vector<int> dists = g.BellmanFord();
  for (int d : dists) {
    cout << d << ' ';
  }
}