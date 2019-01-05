#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  int n = s.size();
  bool has_flake = false;
  int min_length = n;
  int leave_all = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      min_length -= 2;
      leave_all--;
    }
    else if (s[i] == '*') {
      has_flake = true;
      min_length -= 2;
      leave_all--;
    }
  }
  if (k < min_length || (k > leave_all && !has_flake)) {
    cout << "Impossible";
  }
  else {
    if (k > leave_all) {
      int add = k - leave_all;
      string ans;
      for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
          continue;
        }
        else if (s[i] == '*') {
          while (add > 0) {
            ans += s[i - 1];
            add--;
          }
        }
        else {
          ans += s[i];
        }
      }
      cout << ans;
    }
    else {
      int remove = leave_all - k;
      string ans;
      for (int i = 0; i < n; i++) {
        if (i < n - 1 && (s[i + 1] == '?' || s[i + 1] == '*')) {
          if (remove) {
            remove--;
          }
          else {
            ans += s[i];
          }
        }
        else if (s[i] == '?' || s[i] == '*') {
          continue;
        }
        else {
          ans += s[i];
        }
      }
      cout << ans;
    }
  }
}