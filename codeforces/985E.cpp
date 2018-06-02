#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(1e6);
int n, k, d;
vector<int> cum(1e6);
int lo;

int get_sum(int l, int r) {
  if (l > r) return 0;
  if (l == 0) return cum[r];
  return cum[r] - cum[l - 1];
}

void solve(int x) {
  while(a[x - 1] - a[lo] > d) lo++;
  int hi = x - k;
  cum[x] = cum[x - 1];
  if (get_sum(lo, hi) > 0) cum[x]++;
}

int main() {
  cin >> n >> k >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);
  cum[0] = 1;
  lo = 0;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }

  if (cum[n] - cum[n - 1] > 0) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}
