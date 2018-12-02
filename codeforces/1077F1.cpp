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

  vector<long long> dp(n, numeric_limits<long long>::min());
  for (int i = 0; i < k; i++) {
    dp[i] = a[i];
  }

  for (int j = 1; j < x; j++) {
    vector<long long> dp2 = dp;
    for (int i = 0; i < n; i++) {
      for (int p = max(i - k, 0); p < i; p++) {
	dp2[i] = max(dp2[i], dp[p] + a[i]);
      }
    }
    dp = dp2;
  }
  long long ans = -1;
  for (int i = n - k; i < n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
