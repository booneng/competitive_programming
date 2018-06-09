#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> l(n + 1), r(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l.rbegin(), l.rend());
  sort(r.begin(), r.end());

  long long int ans = 0;
  for (int i = 0; i < n + 1; i++) {
    if (l[i] > r[i]) {
      ans += 2 * (l[i] - r[i]);
    }
  }
  cout << ans;
}
