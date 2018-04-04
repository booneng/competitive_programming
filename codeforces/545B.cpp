#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  string ans;
  int count = 0;
  bool s_turn = true;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == t[i]) {
      ans += s[i];
    }
    else if (s_turn) {
      ans += s[i];
      s_turn = false;
      count++;
    }
    else {
      ans += t[i];
      s_turn = true;
      count++;
    }
  }
  if (count % 2) {
    cout << "impossible";
  }
  else {
    cout << ans;
  }
}
