#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  int s = 0;
  int e = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == -1) s++;
    else e++;
  }

  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int te = e;
    int ts = s;
    for (int j = i; j <= n; j += k) {
      if (a[j] == 1) te--;
      else ts--;
    }
    ans = max(ans, abs(te - ts));
  }
  cout << ans;

}