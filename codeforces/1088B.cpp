#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int sub = 0;
  int ai = 0;
  for (int i = 0; i < k; i++) {
    while (ai < n && a[ai] <= sub) {
      ai++;
    }
    if (ai < n) {
      cout << a[ai] - sub << endl;
      sub += a[ai] - sub;
    }
    else {
      cout << 0 << endl;
    }
  }

}
