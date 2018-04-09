#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n], s[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  
  int t[n];
  t[0] = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 0) t[0] += a[i];
  }
  for (int i = 1; i <= n - k; i++) {
    t[i] = t[i - 1];
    if (s[i - 1] == 0) t[i] -= a[i - 1];
    if (s[i + k - 1] == 0) t[i] += a[i + k - 1];
  }
  int max_save = 0;
  int index = -k;
  for (int i = 0; i <= n - k; i++) {
    if (t[i] > max_save) {
      max_save = t[i];
      index = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) ans += a[i];
    else if(i >= index && i < index + k) ans += a[i];
  }
  cout << ans;
  
}
