#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int length = 1;
  while (length * length <= n) {
    length++;
  }
  length--;

  n -= length * length;
  int ans = 2 * length;
  if (n > 0) {
    ans++;
    if (n > length) ans++;
  }
  cout << ans;
}