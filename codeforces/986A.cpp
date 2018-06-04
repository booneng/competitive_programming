#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> a(n);
  vector<int> goods[k];
  for (int i = 0; i < n; i++) {
    int good;
    cin >> good;
    good--;
    goods[good].push_back(i);
  }

  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans[n][k];
  for (int good = 0; good < k; good++) {
    vector<int> dists(n, m + 1);
    queue<int> q;
    for (int i : goods[good]) {
      q.push(i);
      dists[i] = 0;
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i : adj[cur]) {
	if (dists[i] <= dists[cur] + 1) continue;
	dists[i] = dists[cur] + 1;
	q.push(i);
      }
    }
    for (int i = 0; i < n; i++) {
      ans[i][good] = dists[i];
    }
  }

  for (int i = 0; i < n; i++) {
    nth_element(ans[i], ans[i] + s, ans[i] + k);
    int res = 0;
    for (int j = 0; j < s; j++) {
      res += ans[i][j];
    }
    cout << res << ' ';
  }

}
