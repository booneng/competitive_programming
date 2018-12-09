#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << n + 1 << endl;
  int add = 0;
  for (int i = n - 1; i >= 0; i--) {
    int next_multiple = ((a[i] + add) / n + 1) * n;
    int target = next_multiple + i;
    // cout << target << endl;
    int diff = target - (a[i] + add);
    add += diff;
    cout << 1 << ' ' << (i + 1) << ' ' << diff << endl;
  }

  cout << 2 << ' ' << n << ' ' << n;

}
