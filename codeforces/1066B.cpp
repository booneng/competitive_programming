#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int heaters = 0;
  int i = 0;
  while (i < n) {
    int start = -1;
    int cnt = 0;
    for (int j = max(i - r + 1, 0); j <= min(i + r - 1, n - 1); j++) {
      if (a[j]) {
	start = j;
      }
    }
    if (start < 0) {
      cout << -1;
      return 0;
    }
    heaters++;
    i = start + r;
  }
  cout << heaters;

}
