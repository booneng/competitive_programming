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
    queue<int> q;
    q.push(source_);
    vector<bool> in_queue(n_, false);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto& edge : adj_[cur]) {
        int next = edge.first;
        int weight = edge.second;
        if (dists[next] > dists[cur] + weight) {
          dists[next] = dists[cur] + weight;
          if (!in_queue[next]) {
            in_queue[next] = true;
            q.push(next);
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