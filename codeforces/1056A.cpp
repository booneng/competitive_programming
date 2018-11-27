#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> lines(101, 0);
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    while (r--) {
      int num;
      cin >> num;
      lines[num]++;
    }
  }
  for (int i = 1; i <= 100; i++) {
    if (lines[i] == n) cout << i << ' ';
  }
}
