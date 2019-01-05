#include <bits/stdc++.h>

using namespace std;

void check(vector<int>& a, bool& can, int i, int sum) {
  if (i == a.size()) {
    if (sum % 360 == 0) can = true;
    return;
  }
  check(a, can, i + 1, sum + a[i]);
  check(a, can, i + 1, sum - a[i]);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool can = false;
  check(a, can, 0, 0);
  cout << (can ? "YES" : "NO");
}