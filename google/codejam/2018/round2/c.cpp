#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Matching {
private:
  vector<vector<int> > graph;
  vector<int> a;
  vector<int> b;
  vector<bool> visited;
  int res;
  int n;
  
public:
  Matching(int _n) : n(_n) {
    a = vector<int>(n, -1);
    b = vector<int>(n, -1);
    graph.resize(n);
    res = 0;
  }

  bool dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
      if (b[u] == -1) {
	a[v] = u;
	b[u] = v;
	return true;
      }
    }

    for (int u : graph[v]) {
      if (!visited[b[u]] && dfs(b[u])) {
	a[v] = u;
	b[u] = v;
	return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      visited = vector<bool>(n, false);
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }

  void add(int from, int to) {
    graph[from].push_back(to);
  }

  
};

void solve() {
  int n;
  cin >> n;
  int grid[105][105];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  
  int ans = 0;
  for (int color = -n; color <= n; color++) {
    Matching m(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (grid[i][j] == color) m.add(i, j);
      }
    }
    ans += m.solve();
  }
  cout << n * n  - ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }


}
