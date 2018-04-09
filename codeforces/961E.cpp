#include <iostream>
#include <cmath>
#include <vector>

#define ll long long int
using namespace std;

int n;

ll get_sum(int l, int r, ll* ft) {
  ll s1 = 0;
  for (; r > 0; r -= r & -r) {
    s1 += ft[r];
  }
  ll s2 = 0;
  for (; l > 0; l -= l & -l) {
    s2 += ft[l];
  }
  return s1 - s2;
}

int main() {
  cin >> n;
  int a[n + 1];
  vector<int> b[n + 1];
  ll fenwick_tree[n + 2];
  for (int i = 0; i < n + 2; i++) {
    fenwick_tree[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = min(a[i], n);
    b[min(i - 1, a[i])].push_back(i);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= n; j += j & -j) {
      fenwick_tree[j]++;
    }
    for (int j = 0; j < b[i].size(); j++) {
      ll sum = get_sum(b[i][j] - 1, n, fenwick_tree);
      ans += sum;
    }
  }
  cout << ans;
}
