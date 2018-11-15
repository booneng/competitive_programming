#include <bits/stdc++.h>

using namespace std;

void dfs(vector<long long>& res, vector<long long>& add, const vector<vector<int>>& adj, const vector<vector<pair<int, int>>>& queries, int v, int parent, int height, long long sum) {
  for (auto p : queries[v]) {
    add[height] += p.second;
    int r = height + p.first + 1;
    if (r < res.size()) add[r] -= p.second;
  }
  sum += add[height];
  res[v] = sum;

  for (int child : adj[v]) {
    if (child != parent) dfs(res, add, adj, queries, child, v, height + 1, sum);
  }
  
  for (auto p : queries[v]) {
    add[height] -= p.second;
    int r = height + p.first + 1;
    if (r < res.size()) add[r] += p.second;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int m;
  cin >> m;
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < m; i++) {
    int v, d, x;
    cin >> v >> d >> x;
    v--;
    queries[v].push_back({d, x});
  }

  vector<long long> res(n, 0);
  vector<long long> add(n, 0);
  dfs(res, add, adj, queries, 0, 0, 0, 0);
  for (long long i : res) {
    cout << i << ' ';
  }
}

