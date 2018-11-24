#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  sort(a.begin(), a.end());
  long long required = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    required++;
    if (a[i] > prev) {
      prev++;
    }
  }
  required += a[n - 1] - prev;
  long long ans = total - required;
  cout << ans;
}
