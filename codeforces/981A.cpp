#include <iostream>
#include <string>
#include <set>


using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  set<char> c;
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      cout << n;
      return 0;
    }
    c.insert(s[i]);
  }
  if (c.size() > 1) {
    cout << n - 1;
    return 0;
  }
  cout << 0;
  
}
