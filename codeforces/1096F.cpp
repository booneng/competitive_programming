#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  else if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return (a * 1LL * b) % MOD;
}

int modpow(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    p >>= 1;
  }
  return res;
}

int inv(int a) {
  return modpow(a, MOD - 2);
}

void update(vector<int>& f, int x) {
  for (int i = x; i < f.size(); i += (i&-i)) {
    f[i]++;
  }
}

int get(const vector<int>& f, int x) {
  int s = 0;
  for (int i = x; i > 0; i -= (i&-i)) {
    s += f[i];
  }
  return s;
}


int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<bool> known(n + 1, false);

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] > -1) {
      known[p[i]] = true;
    }
  }

  vector<int> unknown_cnt(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    unknown_cnt[i] = unknown_cnt[i - 1];
    if (p[i - 1] == -1) unknown_cnt[i]++;
  }

  vector<int> unknown_cnt_rev(n + 1, 0);
  for (int i = n - 2; i >= 0; i--) {
    unknown_cnt_rev[i] = unknown_cnt_rev[i + 1];
    if (p[i + 1] == -1) unknown_cnt_rev[i]++;
  }

  vector<int> greater_unknown_cnt(n + 1, 0);
  for (int i = n - 1; i > 0; i--) {
    greater_unknown_cnt[i] = greater_unknown_cnt[i + 1];
    if (!known[i + 1]) {
      greater_unknown_cnt[i]++;
    }
  }

  vector<int> lesser_unknown_cnt(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    lesser_unknown_cnt[i] = lesser_unknown_cnt[i - 1];
    if (!known[i - 1]) {
      lesser_unknown_cnt[i]++;
    }
  }

  int ans = 0;
  int uc = unknown_cnt[n];
  // unknown, unknown
  ans = add(ans, mul(uc, mul(uc - 1, inv(4))));

  // known, unknown
  for (int i = 0; i < n; i++) {
    if (p[i] > -1) {
      ans = add(ans, mul(unknown_cnt[i], mul(greater_unknown_cnt[p[i]], inv(uc))));
      ans = add(ans, mul(unknown_cnt_rev[i], mul(lesser_unknown_cnt[p[i]], inv(uc))));
    }
  }

  // known, known
  vector<int> f(n + 1, 0);
  int tmp = 0;
  for (int i : p) {
    if (i > -1) {
      ans = add(ans, tmp - get(f, i));
      update(f, i);
      tmp++;
    }
  }
  cout << ans;
}