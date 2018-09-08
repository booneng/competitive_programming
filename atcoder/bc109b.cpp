#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  string s;
  set<string> seen;
  cin >> s;
  char c = s[s.size() - 1];
  bool ok = true;
  seen.insert(s);
  for (int i = 1; i < n; i++) {
    cin >> s;
    if ((s[0] != c) || (seen.find(s) != seen.end())) {
      ok = false;
    }
    seen.insert(s);
    c = s[s.size() - 1];
  }
  cout << (ok ? "Yes" : "No");

}
