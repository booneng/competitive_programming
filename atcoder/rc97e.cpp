#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int a[4005];
char col[4005];
int cw[2005][2005];
int cb[2005][2005];
int b[2005];
int w[2005];
int counts_b[2005];
int counts_w[2005];
int dp[2005][2005];

int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> col[i] >> a[i];
    a[i]--;
    if (col[i] == 'W') w[a[i]] = i;
    else b[a[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    int count_b = 0;
    int count_w = 0;
    for (int j = 0; j < i; j++) {
      if (b[i] < b[j]) count_b++;
      if (w[i] < w[j]) count_w++;
    }
    counts_b[i] = count_b;
    counts_w[i] = count_w;
  }

  cb[0][0] = 0;
  cw[0][0] = 0;
  for (int i = 0; i < n; i++) {
    cb[i][0] = counts_b[i];
    cw[i][0] = counts_w[i];
    int count_b = counts_b[i];
    int count_w = counts_w[i];
    for (int j = 0; j < n; j++) {
      if (b[i] < w[j]) count_b++;
      if (w[i] < b[j]) count_w++;
      cb[i][j + 1] = count_b;
      cw[i][j + 1] = count_w;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + cb[i - 1][0];
    dp[0][i] = dp[0][i - 1] + cw[i - 1][0];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i - 1][j] + cb[i - 1][j], dp[i][j - 1] + cw[j - 1][i]);
    }
  }
  cout << dp[n][n];
}
