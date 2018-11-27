#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (((i * i + j * j) % m) == 0) {
	long long cnt1 = n / m;
	if (n % m >= i) cnt1++;
	if (i == 0) cnt1--;
	long long cnt2 = n / m;
	if (n % m >= j) cnt2++;
	if (j == 0) cnt2--;
	ans += cnt1 * cnt2;
      }
    }
  }
  cout << ans;
}
