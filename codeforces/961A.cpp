#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int counts[n];
  for (int i = 0; i < n; i++) counts[i] = 0;
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c;
    counts[c - 1]++;
  }
  int ans = 1000;
  for (int i = 0; i < n; i++) {
    ans = min(ans, counts[i]);
  }
  cout << ans;
}
