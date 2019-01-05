#include <bits/stdc++.h>

using namespace std;

int main() {
  string s1;
  cin >> s1;
  bool can = false;
  for (int i = 0; i < 5; i++) {
    string s2;
    cin >> s2;
    if (s1[0] == s2[0] || s1[1] == s2[1]) {
      can = true;
      break;
    }
  }
  cout << (can ? "YES" : "NO");
}