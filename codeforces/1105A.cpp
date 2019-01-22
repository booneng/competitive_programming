#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int min_cost = 100000;
  int min_t = 0;
  for (int t = 1; t <= 100; t++) {
    int cur_cost = 0;
    for (int i = 0; i < n; i++) {
      int c = min(abs(a[i] - t), min(abs(a[i] - 1 - t), abs(a[i] + 1 - t)));
      cur_cost += c;
    }
    if (cur_cost < min_cost) {
      min_cost = cur_cost;
      min_t = t;
    }
  }
  cout << min_t << ' ' << min_cost;
}