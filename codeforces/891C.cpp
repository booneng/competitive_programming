#include <bits/stdc++.h>

using namespace std;

int parents[500005];
int parents2[500005];
int time_clock[500005];
int u[500005], v[500005], w[500005];
vector<pair<int, int>> qw[500005];
vector<int> edges[500005];
int cannot[500005];
int t;

int find(int i) {
  if (parents[i] == i) return i;
  parents[i] = find(parents[i]);
  return parents[i];
}

int find2(int i) {
  if (time_clock[i] != t) {
    time_clock[i] = t;
    parents2[i] = parents[i];
  }
  if (parents2[i] != i) {
    parents2[i] = find2(parents2[i]);
  }
  return parents2[i];
}

void join(int i, int j) {
  int pi = find(i);
  int pj = find(j);
  
  parents[pi] = pj;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  t = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    edges[w[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int e;
      cin >> e;
      e--;
      qw[w[e]].push_back({i, e});
    }
  }

  for (int i = 1; i < 500005; i++) {
    sort(qw[i].begin(), qw[i].end());
    // for (int j = 0; j < qw[i].size(); j++) {
    //   int edge_id = qw[i][j].second;
    //   int x = u[edge_id];
    //   int y = v[edge_id];
    //   find(x);
    //   find(y);
    // }
    for (int j = 0; j < qw[i].size(); j++) {
      if (j==0 || qw[i][j].first != qw[i][j - 1].first) t++;
      int query_id = qw[i][j].first;
      int edge_id = qw[i][j].second;
      int x = u[edge_id];
      int y = v[edge_id];
      if (find2(x) == find2(y)) {
        cannot[query_id] = 1;
      }
      parents2[find2(x)] = find2(y);
    }

    for (int j = 0; j < edges[i].size(); j++) {
      int x = u[edges[i][j]];
      int y = v[edges[i][j]];
      parents[find(x)] = find(y);
    }
  }

  for (int i = 0; i < q; i++) {
    puts(cannot[i]?"NO":"YES");
    // if (cannot[i]) {
    //   cout << "NO" << endl;
    // }
    // else {
    //   cout << "YES" << endl;
    // }
  }
}