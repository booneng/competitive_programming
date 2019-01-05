#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

unordered_map<int, unordered_map<int, int>> dp;
unordered_map<int, vector<pair<long long, long long>>> ddp;

int mul(int a, int b) {
  return (a * 1LL * b) % MOD;
}

int add(int a, int b) {
  a += b;
  if (a >= MOD) a-= MOD;
  else if (a < 0) a += MOD;
  return a;
}

int modpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return modpow(a, MOD - 2);
}

int main() {
  long long n;
  int k;
  cin >> n >> k;
  vector<pair<long long, int>> divisors;
  int maximum_power = 1;
  for (int i = 2; i <= ((int) sqrt(n) + 1); i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    if (cnt) {
      divisors.push_back({i, cnt});
      maximum_power = max(maximum_power, cnt);
    }
  }
  if (n > 1) divisors.push_back({n % MOD, 1});

  int ans = 1;
  for (int i = 0; i < divisors.size(); i++) {
    int power = divisors[i].second;
    vector<vector<int>> dp(k + 1, vector<int>(power + 1));
    dp[0][power] = 1;
    for (int j = 1; j <= k; j++) {
      dp[j][power] = mul(dp[j - 1][power], inv(power + 1));
      for (int p = power - 1; p >= 0; p--) {
        dp[j][p] = add(dp[j][p + 1], mul(dp[j - 1][p], inv(p + 1)));
      }
    }
    int expected = 0;
    int term = 1;
    for (int j = 0; j <= power; j++) {
      expected = add(expected, mul(dp[k][j], term));
      term = mul(term, divisors[i].first);
    }
    ans = mul(ans, expected);
  }
  cout << ans;
}