#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << setprecision(10);
  cout << fixed;
  int n, s;
  cin >> n >> s;
  vector<int> cnts(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnts[a]++;
    cnts[b]++;
  }

  int leaves = 0;
  for (int i = 0; i < n; i++) {
    if (cnts[i] == 1) leaves++;
  }
  cout << 2.0 * s / leaves;

}