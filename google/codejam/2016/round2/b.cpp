#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  cout << fixed;
  for (int t = 1; t <= T; t++) {
    int n, k;
    cin >> n >> k;
    vector<double> p(205);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    p[0] = 0;
    sort(p.begin(), p.begin() + n + 1);
    double dp[205][205];
    double max_p = 0;
    for (int m = 0; m <= k; m++) {
      vector<double> vals(k + 1);
      for (int i = 1; i <= m; i++) {
	vals[i] = p[i];
      }
      for (int i = m + 1; i <= k; i++) {
	vals[i] = p[n - k + i];
      }
      for (int i = 0; i <= k; i++) {
	for (int j = 0; j <= k; j++) {
	  dp[i][j] = 0;
	}
      }
      dp[0][0] = 1;
      for (int j = 1; j <= k; j++) {
	dp[0][j] = dp[0][j - 1] * (1 - vals[j]);
      }
      for (int i = 1; i <= k / 2; i++) {
	for (int j = i; j <= k; j++) {
	  dp[i][j] = dp[i][j - 1] * (1 - vals[j]) + dp[i - 1][j - 1] * vals[j];
	}
      }
      max_p = max(max_p, dp[k / 2][k]);
    }
    cout << "Case #" << t << ": " << max_p << endl;
  }
}
