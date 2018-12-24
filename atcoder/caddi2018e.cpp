#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long dp[2][n][16];
  for (int i = 0; i < 16; i++) {
    dp[0][n - 1][i] = i;
    dp[1][n - 1][i] = i;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = n - 2; j >= 0; j--) {
      int j1 = 0;
      int j2 = 0;
      long long c1 = a[j];
      long long c2 = a[j + 1];
      while (c1 <= c2 && j1 < 16) {
        dp[i][j][j1] = dp[i][j + 1][0] + j1;
        c1 *= 4;
        j1++;
      }
      while (j2 < 16 && c2 < c1) {
        c2 *= 4;
        j2++;
      }
      while (j1 < 16) {
        if (j2 > 15) {
          dp[i][j][j1] = dp[i][j + 1][15] + (j2 - 15) * (n - 1 - j) + j1;
        }
        else {
          dp[i][j][j1] = dp[i][j + 1][j2] + j1;
        }
        j1++;
        j2++;
      }
    }
    reverse(a, a + n);
  }

  long long ans = 2 * dp[0][0][0];
  for (int i = 1; i < n; i++) {
    long long steps = dp[0][i][0] * 2 + dp[1][n - i][0] * 2 + i;
    ans = min(ans, steps);
  }
  cout << ans;
}
