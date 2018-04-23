#include <iostream>

using namespace std;

int main() {
  int n, a, b, c, t;
  cin >> n >> a >> b >> c >> t;
  int ts[1000];
  for (int i = 0; i < n; i++) {
    cin >> ts[i];
  }
  int ans = n * a;
  if (b < c) {
    for (int i = 0; i < n; i++) {
      ans += (t - ts[i]) * (c - b);
    }
  }
  cout << ans;
}
