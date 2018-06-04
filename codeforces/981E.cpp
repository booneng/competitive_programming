#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MX = 10 * 1000 + 3;

bitset<MX> ans;
vector<int> add[4 * MX];
int n, q;

void ad(int v, int tl, int tr, int l, int r, int x) {
  if (r < tl || l > tr) return;
  
  if (tl >= l && tr <= r) {
    add[v].push_back(x);
    return;
  }

  int tm = (tl + tr) >> 1;
  ad(v + v, tl, tm, l, r, x);
  ad(v + v + 1, tm + 1, tr, l, r, x);
}

void dfs(int v, int tl, int tr, bitset<MX> dp) {
  // dp[0] starts as 1 so any x in any add[v] will
  // always be true in the resulting bitset
  for (int x : add[v]) {
    dp |= (dp << x);
  }

  if (tl == tr) {
    ans |= dp;
  }
  else {
    int tm = (tl + tr) >> 1;
    dfs(v + v, tl, tm, dp);
    dfs(v + v + 1, tm + 1, tr, dp);
  }
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    ad(1, 1, n, l, r, x);
  }

  bitset<MX> st;
  st[0] = true;
  dfs(1, 1, n, st);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) res++;
  }

  cout << res << endl;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) cout << i << ' ';
  }
}
