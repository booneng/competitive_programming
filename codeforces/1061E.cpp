#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g1(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }
  vector<vector<int>> g2(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }

  int q1;
  cin >> q1;
  for (int i = 0; i < q1; i++) {

  }

  int q2;
  cin >> q2;
  for (int i = 0; i < q2; i++) {

  }
}
