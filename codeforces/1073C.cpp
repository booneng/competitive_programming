#include <bits/stdc++.h>

using namespace std;

void move(int& x, int& y, char c, int m) {
  if (c == 'U') y += m;
  else if (c == 'D') y -= m;
  else if (c == 'R') x += m;
  else if (c == 'L') x -= m;
}

bool can(const int& n, const int& len, const int& x, const int& y, const string& steps) {
  int cx = 0;
  int cy = 0;
  for (int i = len; i < n; i++) {
    move(cx, cy, steps[i], 1);
  }
  int d = abs(cx - x) + abs(cy - y);
  if (d <= len && (d % 2) == (len % 2)) {
    return true;
  }

  for (int i = len; i < n; i++) {
    move(cx, cy, steps[i - len], 1);
    move(cx, cy, steps[i], -1);
    
    d = abs(cx - x) + abs(cy - y);
    if (d <= len && (d % 2) == (len % 2)) {
      return true;
    }
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
  int cx = 0;
  int cy = 0;
  for (int i = 0; i < n; i++) {
    move(cx, cy, steps[i], 1);
    xsums[i + 1] = cx;
    ysums[i + 1] = cy;
  }

  int ans = n;
  int l = 0;
  for (int r = 0; r < n; r++) {
    while (l < r && can(l, r, cx, cy, x, y)) l++;
    if (can(l - 1, r, cx, cy, x, y)) {
      ans = min(ans, r - l + 1);
    }
  }
  cout << ans;
}
