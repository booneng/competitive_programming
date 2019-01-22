#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int max_level = 0;
  for (int i = 0; i < 26; i++) {
    int cnt = 0;
    char c = 'a' + i;
    int level = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == c) {
        cnt++;
      }
      else {
        level += cnt / k;
        cnt = 0;
      }
    }
    level += cnt / k;
    if (level > max_level) {
      max_level = level;
    }
  }
  cout << max_level;
}