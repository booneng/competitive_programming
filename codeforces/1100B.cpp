#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> difficulties(n + 1, 0);
  int rem = n;
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    if (difficulties[d] == 0) {
      rem--;
    }
    difficulties[d]++;
    if (rem == 0) {
      cout << 1;
      for (int j = 1; j <= n; j++) {
        difficulties[j]--;
        if (difficulties[j] == 0) {
          rem++;
        }
      }
    }
    else {
      cout << 0;
    }
  }
}