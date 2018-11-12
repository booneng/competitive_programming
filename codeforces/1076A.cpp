#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] < s[i - 1]) {
      s = s.substr(0, i - 1) + s.substr(i);
      cout << s;
      return 0;
    }
  }
  cout << s.substr(0, n - 1);
}
