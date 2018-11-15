#include <bits/stdc++.h>

using namespace std;

int main() {
  long long mod = 1000000007;
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> ones(n + 1, 0);
  vector<long long> twop(n + 1);
  twop[0] = 1;
  for (int i = 1; i <= n; i++) {
    twop[i] = (twop[i - 1] * 2) % mod;
  }
  for (int i = 1; i <= n; i++) {
    ones[i] = ones[i - 1];
    if (s[i - 1] == '1') ones[i]++;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    int o = ones[r] - ones[l - 1];
    int z = len - o;
    long long ans = (twop[z] * (twop[o] - 1)) % mod;
    cout << ans << endl;
  }

}
