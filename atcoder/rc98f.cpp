#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  
  vector<int> add(n);
  iota(add.begin(), add.end(), 0);
  sort(add.begin(), add.end(), [&](int i, int j) {
      return a[i] - b[i] < a[j] - b[j];
    });

  vector<bool> visited(n, false);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  for (int i : add) {
    if (i == max_index) continue;
    for (int j : graph[i]) {
      if (visited[j]) {
	int x = j;
	while (x != p[x]) {
	  x = p[x];
	}
	p[x] = i;
      }
    }
    visited[i] = true;
  }

  vector<int> ans(n, -1);
  vector<int> sum_b(n, 0);
  
  for (int i : add) {
    int prev = 0;
    if (ans[i] > 0) continue;
    int x = i;
    int sum = 0;
    while (x != p[x]) {
      int need = max(a[x], b[x]);
      int cur = prev + b[x];
      prev = max(need, cur);
      sum += b[x];
      ans[x] = prev;
      x = p[x];
    }
    int need = max(a[x], b[x]);
    int cur = prev + b[x];
    prev = max(need, cur);
    sum += b[x];
    sum_b[x] = sum;
    ans[x] = prev;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i == max_index) {
      continue;
    }
    if (i == p[i]) {
      cout << "TEST" << ans[i] << ' ' << sum_b[i] << endl;
      res = max(ans[i], res + sum_b[i]);
    }
  }
  cout << "MAX  " << a[max_index] << ' ' << b[max_index] << endl;
  res = max(a[max_index], res + b[max_index]);
  cout << res;
  return 0;
}
