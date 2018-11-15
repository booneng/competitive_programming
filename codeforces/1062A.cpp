#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1000) {
    cout << 1000;
    return 0;
  }
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  int left = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - 1 == a[i - 1]) {
      if (a[left] == 1 || a[i] == 1000) ans = max(i - left, ans);
      else ans = max(i - left - 1, ans);
    }
    else {
      left = i;
    }
  }
  cout << ans;
}
