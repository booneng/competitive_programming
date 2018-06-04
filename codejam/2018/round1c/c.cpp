#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long int

using namespace std;

int n;
ll w[100005];
ll dp[100005][145];
const ll INF = 1e12;

void solve() {
  cin >> n;
  int k = 140;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  dp[0][1] = w[0];
  for (int i = 2; i <= k; i++) {
    dp[0][i] = INF;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j - 1] <= 6 * w[i]) {
	dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + w[i]);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    if (dp[n - 1][i] < INF) ans = i;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
