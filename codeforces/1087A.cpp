#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string ans;
  int left = 0;
  int right = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (i % 2) {
      ans = s[right--] + ans;
    }
    else {
      ans = s[left++] + ans;
    }
  }
  cout << ans;
}