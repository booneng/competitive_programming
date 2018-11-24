#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  int amax = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    amax = max(amax, a[i]);
  }
  vector<vector<int>> divs(amax + 1);
  for (int i = 1; i <= amax; i++) {
    for (int j = i; j <= amax; j+=i) {
      divs[j].push_back(i);
    }
  }
  int mod = 1000000007;
  vector<int> dp(amax + 1, 0);
  dp[0] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j : divs[a[i]]) {
      ans = (ans + dp[j - 1]) % mod;
    }
    for (int j = divs[a[i]].size() - 1; j >= 0; j--) {
      int k = divs[a[i]][j];
      dp[k] = (dp[k] + dp[k - 1]) % mod;
    }
  }
  cout << ans;
}
