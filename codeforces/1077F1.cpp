#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x < n / k) {
    cout << -1;
    return 0;
  }

  vector<vector<long long>> dp(n, vector<long long>(x, numeric_limits<long long>::min()));
  for (int i = 0; i < k; i++) {
    dp[i][0] = a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < x; j++) {
      for (int p = max(i - k, 0); p < i; p++) {
	dp[i][j] = max(dp[i][j], dp[p][j - 1] + a[i]);
      }
    }
  }
  long long ans = -1;
  for (int i = n - k; i < n; i++) {
    ans = max(ans, dp[i][x - 1]);
  }
  cout << ans;
}
