#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int dp[n][n][n + 1];
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      dp[l][r][0] = a[r] - a[l];
      int j = l;
      for (int k = 1; k <= n; k++) {
        while (j < r && (max(dp[l][j][k - 1], a[r] - a[j]) > max(dp[l][j + 1][k - 1], a[r] - a[j + 1])))
          j++;
        dp[l][r][k] = max(dp[l][j][k - 1], a[r] - a[j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int s, f, c, r;
    cin >> s >> f >> c >> r;
    s--;
    f--;
    long long tank = c * 1LL * dp[s][f][r];
    ans = max(ans, tank);
  }
  cout << ans;
}