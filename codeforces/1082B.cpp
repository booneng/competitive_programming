#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int gs = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') gs++;
  }
  int prev = 0;
  int cur = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      cur++;
    }
    else {
      ans = max(ans, 1 + prev + cur);
      prev = cur;
      cur = 0;
    }
  }
  ans = max(ans, 1 + prev + cur);
  cout << min(ans, gs);
}
