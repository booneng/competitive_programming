#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int mul(int a, int b) {
  return (a * 1LL * b) % mod;
}

int add(int a, int b) {
  int res = a + b;
  if (res >= mod) res -= mod;
  else if (res < 0) res += mod;
  return res;
}

int main() {
  int n;
  cin >> n;
  int facs[n + 1];
  facs[0] = 1;
  for (int i = 1; i <= n; i++) {
    facs[i] = mul(facs[i - 1], i);
  }
  int ans = facs[n];
  int times = n;
  for (int i = n - 1; i > 1; i--) {
    int term = mul(add(facs[i], -1), times);
    times = mul(times, i);
    ans = add(ans, term);
  }
  cout << ans;
}