#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<long long>> dp(n, vector<long long>(16));
  vector<vector<long long>> dp2(n, vector<long long>(16));
  for (int i = 0; i < 16; i++) {
    dp[n - 1][i] = i;
    dp2[0][i] = i;
  }

  for (int i = n - 2; i >= 0; i--) {
    long long j1 = 0;
    long long j2 = 0;
    long long c1 = a[i];
    long long c2 = a[i + 1];
    while (c1 <= c2 && j1 < 16) {
      dp[i][j1] = dp[i + 1][0] + j1;
      c1 *= 4;
      j1++;
    }
    while (j2 < 16 && c2 < c1) {
      c2 *= 4;
      j2++;
    }
    while (j1 < 16) {
      if (j2 > 15) {
        dp[i][j1] = dp[i + 1][15] + (j2 - 15) * (n - 1 - i) + j1;
      }
      else {
        dp[i][j1] = dp[i + 1][j2] + j1;
      }
      j1++;
      j2++;
    }
  }

  for (int i = 1; i < n; i++) {
    long long j1 = 0;
    long long j2 = 0;
    long long c1 = a[i];
    long long c2 = a[i - 1];
    while (c1 <= c2 && j1 < 16) {
      dp2[i][j1] = dp2[i - 1][0] + j1;
      c1 *= 4;
      j1++;
    }
    while (j2 < 16 && c2 < c1) {
      c2 *= 4;
      j2++;
    }
    while (j1 < 16) {
      if (j2 > 15) {
        dp2[i][j1] = dp2[i - 1][15] + (j2 - 15) * i + j1;
      }
      else {
        dp2[i][j1] = dp2[i - 1][j2] + j1;
      }
      j1++;
      j2++;
    }
  }

  long long ans = 2 * dp[0][0];
  for (int i = 1; i < n; i++) {
    long long steps = dp[i][0] * 2 + dp2[i - 1][0] * 2 + i;
    ans = min(ans, steps);
  }
  cout << ans;
}
