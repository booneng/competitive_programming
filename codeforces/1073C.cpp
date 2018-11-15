#include <bits/stdc++.h>

using namespace std;

void move(int& x, int& y, char c, int m) {
  if (c == 'U') y += m;
  else if (c == 'D') y -= m;
  else if (c == 'R') x += m;
  else if (c == 'L') x -= m;
}

bool can(int l, int r, int cx, int cy, int x, int y, int* xsums, int* ysums) {
  int len = r - l;
  cx -= xsums[r] - xsums[l];
  cy -= ysums[r] - ysums[l];
  int d = abs(cx - x) + abs(cy - y);
  if (d <= len && (d % 2) == (len % 2)) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  string steps;
  cin >> steps;
  int x, y;
  cin >> x >> y;
  int d = abs(x) + abs(y);
  if (d % 2 != n % 2 || d > n) {
    cout << -1;
    return 0;
  }

  int xsums[n + 1];
  int ysums[n + 1];
  xsums[0] = 0;
  ysums[0] = 0;
  int cx = 0;
  int cy = 0;
  for (int i = 0; i < n; i++) {
    move(cx, cy, steps[i], 1);
    xsums[i + 1] = cx;
    ysums[i + 1] = cy;
  }
  int ans = n;
  int l = 0;
  for (int r = 0; r <= n; r++) {
    while (l <= r && can(l, r, cx, cy, x, y, xsums, ysums)) l++;
    if (l > 0 && can(l - 1, r, cx, cy, x, y, xsums, ysums)) {
      ans = min(ans, r - l + 1);
    }
  }
  cout << ans;
}
