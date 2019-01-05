#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h;
  int u1, d1, u2, d2;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  if (d2 > d1) {
    swap(d1, d2);
    swap(u1, u2);
  }

  int diff = h - d1;
  w += (h + 1) * h / 2 - d1 * (d1 - 1) / 2;
  w = max(w - u1, 0);

  w += d1 * (d1 - 1) / 2 - d2 * (d2 - 1) / 2;
  w = max(w - u2, 0);

  w += d2 * (d2 - 1) / 2;
  cout << w;
}