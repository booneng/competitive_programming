#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int w;
  cin >> w;

  for (int i = 0; i < s.length(); i++) {
    if (i % w == 0) cout << s[i];
  }

}
