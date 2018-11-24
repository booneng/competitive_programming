#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int rows = n / 20;
  if (n % 20) rows++;
  int rem = n % rows;
  int cols = n / rows;
  if (rem > 0) cols++;
  cout << rows << ' ' << cols << endl;
  for (int i = 0; i < rem; i++) {
    cout << s.substr(0, cols) << endl;
    s = s.substr(cols);
  }
  if (rem > 0) cols--;
  for (int i = 0; i < rows - rem; i++) {
    cout << s.substr(0, cols);
    if (rem) cout << '*';
    cout << endl;
    s = s.substr(cols);
  }

}
