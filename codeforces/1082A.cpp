#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    int diff = abs(y - x);
    if (diff % d == 0) {
      cout << (diff / d) << endl;
    }
    else {
      int d1 = (y - 1);
      int d2 = (n - y);
      int steps = 2 * n;
      if (d1 % d == 0) {
	int tmp = d1 / d;
	if (x > 1) tmp += (x - 2) / d + 1;
	steps = min(steps, tmp);
	// cout << "TEST " << steps << endl;
      }
      if (d2 % d == 0) {
	int tmp = d2 / d;
	if (x < n) tmp += (n - x - 1) / d + 1;
	steps = min(steps, tmp);
	// cout << "TEST 2 " << steps << endl;
      }
      if (steps < 2 * n) cout << steps << endl;
      else cout << -1 << endl;
    }
  }

}
