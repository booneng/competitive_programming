#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int start = s.find('[');
  int end = s.rfind(']');
  if (start == string::npos || end == string::npos || start > end) {
    cout << -1;
    return 0;
  }

  int start2 = s.find(':', start);
  int end2 = s.rfind(':', end);
  if (start2 == string::npos || end2 == string::npos || start2 >= end2) {
    cout << -1;
    return 0;
  }

  int ans = 4;
  for (int i = start2; i < end2; i++) {
    if (s[i] == '|') {
      ans++;
    }
  }
  cout << ans;
}