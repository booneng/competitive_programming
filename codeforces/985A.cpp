#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n / 2);
  for (int i = 0; i < n / 2; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < n / 2; i++) {
    int pos = p[i];
    ans1 += fabs(2 * i + 1 - pos);
    ans2 += fabs(2 * (i + 1) - pos);
  }
  cout << min(ans1, ans2);
}
