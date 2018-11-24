#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> utensilcnt;
  int maxcnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    utensilcnt[a]++;
    maxcnt = max(maxcnt, utensilcnt[a]);
  }

  int dishes;
  if (maxcnt % k != 0) {
    dishes = k * (maxcnt / k + 1);
  }
  else {
    dishes = maxcnt;
  }

  int ans = 0;
  for (auto it = utensilcnt.begin(); it != utensilcnt.end(); it++) {
    ans += dishes - it->second;
  }
  cout << ans;
  

}
