#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x[n + m];
  for (int i = 0; i < n + m; i++) {
    cin >> x[i];
  }
  int taxis[m];
  int p = 0;
  for (int i = 0; i < n + m; i++) {
    int t;
    cin >> t;
    if (t) taxis[p++] = x[i];
  }

  int current = 0;
  int currentTaxiIndex = 0;
  for (int i = 0; i < n + m; i++) {
    if (currentTaxiIndex < m - 1 && x[i] - taxis[currentTaxiIndex] > taxis[currentTaxiIndex + 1] - x[i]) {
      cout << current << ' ';
      currentTaxiIndex++;
      current = 0;
    }
    if (!t[i]) {
      current++;
    }
  }
  cout << current;
}
