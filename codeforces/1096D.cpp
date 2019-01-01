#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string t = "hard";
  int m = t.size();
  vector<vector<long long>> dp(n, vector<long long>(m, 0));
  dp[0][0] = (s[0] == t[0]) ? a[0] : 0;
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0];
    if (s[i] == t[0]) {
      dp[i][0] += a[i];
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + a[i]);
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n - 1][m - 1];
}