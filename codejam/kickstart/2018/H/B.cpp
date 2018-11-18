#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string beauty;
  cin >> beauty;
  vector<int> presum(n + 1, 0);
  for (int i = 0; i < n; i++) {
    presum[i + 1] = presum[i] + (beauty[i] - '0');
  }
  int walls = n % 2 ? (n / 2 + 1) : n / 2;
  int ans = 0;
  for (int i = 0; i <= n - walls; i++) {
    ans = max(ans, presum[i + walls] - presum[i]);
  }
  cout << ans << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
