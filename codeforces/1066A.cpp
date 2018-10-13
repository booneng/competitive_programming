#include <iostream>

using namespace std;

void solve() {
  int L, v, l, r;
  cin >> L >> v >> l >> r;
  int n = L / v - r / v + (l - 1) / v;
  cout << n << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

}
