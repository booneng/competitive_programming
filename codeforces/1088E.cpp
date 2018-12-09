#include <bits/stdc++.h>

using namespace std;

long long dp[300005];
vector<int> adj[300005];
int k = 0;
long long ans = -1e9;
int a[300005];

void dfs(int i, int parent, bool f) {
  dp[i] = a[i];
  for (int u : adj[i]) {
    if (u == parent) continue;
    dfs(u, i, f);
    dp[i] += max(dp[u], 0LL);
  }

  if (f) {
    ans = max(ans, dp[i]);
  }
  else if (dp[i] == ans) {
    dp[i] = 0;
    k++;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, true);
  dfs(1, 0, false);

  cout << ans * k << ' ' << k;

}
