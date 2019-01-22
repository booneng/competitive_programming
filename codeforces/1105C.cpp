#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int add(int a, int b) {
  return (a + b) % MOD;
}

int mul(int a, int b) {
  return (a * 1LL * b) % MOD;
}


int main() {
  int n, l, r;
  cin >> n >> l >> r;

  int cnts[3];
  int len = r - l + 1;
  cnts[0] = len / 3;
  cnts[1] = len / 3;
  cnts[2] = len / 3;
  for (int i = 0; i < len % 3; i++) {
    cnts[(i + l) % 3]++;
  }
  // cout << cnts[0] << ' ' << cnts[1] << ' ' << cnts[2] << endl;
  // i is how many pairs of 1,2 to include
  int ans = 0;
  int dp[n][3];
  dp[0][0] = cnts[0];
  dp[0][1] = cnts[1];
  dp[0][2] = cnts[2];
  for (int i = 1; i < n; i++) {
    dp[i][0] = add(add(mul(dp[i - 1][0], cnts[0]), mul(dp[i - 1][1], cnts[2])), mul(dp[i - 1][2], cnts[1]));
    dp[i][1] = add(add(mul(dp[i - 1][0], cnts[1]), mul(dp[i - 1][1], cnts[0])), mul(dp[i - 1][2], cnts[2]));
    dp[i][2] = add(add(mul(dp[i - 1][0], cnts[2]), mul(dp[i - 1][1], cnts[1])), mul(dp[i - 1][2], cnts[0]));
    // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
  }
  cout << dp[n - 1][0];
}