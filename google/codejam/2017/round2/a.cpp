#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, p;
    cin >> n >> p;
    int groups[5] = {0};
    for (int j = 0; j < n; j++) {
      int g;
      cin >> g;
      groups[g % p]++;
    }

    int ans;
    if (p == 2) {
      ans = groups[0] + (groups[1] + 1) / 2;
    }
    else if (p == 3) {
      int middle = min(groups[1], groups[2]);
      int end = fabs(groups[1] - groups[2]);
      if (end % 3) end = end / 3 + 1;
      else end = end / 3;
      ans = groups[0] + middle + end;
    }
    else if (p == 4) {
      int temp = 2 * (groups[2] % 2) + fabs(groups[1] - groups[3]);
      if (temp % 4) temp = temp / 4 + 1;
      else temp /= 4;
      ans = groups[0] + groups[2] / 2 + min(groups[1], groups[3]) + temp;
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
}
