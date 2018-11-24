#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n, vector<int>(5, -1));

  for (int i = 0; i < 5; i++) dp[0][i] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
	if (dp[i - 1][k] >= 0) {
	  if (a[i] > a[i - 1] && k < j) {
	    dp[i][j] = k;
	    break;
	  }
	  else if (a[i] < a[i - 1] && k > j) {
	    dp[i][j] = k;
	    break;
	  }
	  else if (a[i] == a[i - 1] && k != j) {
	    dp[i][j] = k;
	    break;
	  }
	}
      }
    }
  }

  int ind = -1;
  vector<int> ans(n);
  for (int i = 0; i < 5; i++) {
    if (dp[n - 1][i] >= 0) {
      ans[n - 1] = i + 1;
      ind = i;
      break;
    }
  }
  if (ind == -1) {
    cout << -1;
  }
  else {
    for (int i = n - 1; i > 0; i--) {
      ind = dp[i][ind];
      ans[i - 1] = ind + 1;
    }
    for (int i : ans) cout << i << ' ';
  }
}
