#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int M = 100005;

vector<pair<int, int>> adj[N];
vector<int> roads[M];
bool visited[N];
bool rec_stack[N];
int components[N];
int order[N];
int n, m;
int k;
int o;

bool dfs(int i) {
  visited[i] = true;
  rec_stack[i] = true;
  for (auto p : adj[i]) {
    int j = p.first;
    int cost = p.second;
    if (cost <= k) continue;
    if (rec_stack[j]) {
      return false;
    }
    if (visited[j]) continue;
    if (!dfs(j)) return false;
  }
  order[i] = o;
  o++;
  rec_stack[i] = false;
  return true;
}

bool check() {
  memset(visited, false, n + 1);
  memset(rec_stack, false, n + 1);

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    if (!dfs(i)) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    roads[i] = {u, v, c};
    adj[u].push_back({v, c});
  }

  int left = 0;
  int right = 1e9;
  while (left <= right) {
    int mid = (left + right) / 2;
    k = mid;
    bool res = check();
    // cout << mid << ' ' << res << endl;
    if (res) {
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }

  k = left;
  o = 0;
  check();
  vector<int> removals;
  for (int i = 0; i < m; i++) {
    int u = roads[i][0];
    int v = roads[i][1];
    int w = roads[i][2];
    if (w <= left && order[u] < order[v]) {
      removals.push_back(i + 1);
    }
  }

  cout << left << ' ' << removals.size() << endl;
  for (int r : removals) cout << r << ' ';



}