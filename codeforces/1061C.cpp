#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<int> divisors;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        divisors.push_back(j);
        if (j * j != a[i]) {
          divisors.push_back(a[i] / j);
        }
      }
    }

    sort(divisors.begin(), divisors.end(), greater<int>());

    for (int& div : divisors) {
      if (div > n) continue;
      dp[div] = (dp[div] + dp[div - 1]) % MOD;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[i]) % MOD;
  }
  cout << ans;
}
