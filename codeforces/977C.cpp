#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  if (k == n) cout << a[n - 1];
  else if ((k > 0 && a[k] == a[k - 1]) || (k == 0 && a[0] == 1)) cout << -1;
  else cout << a[k] - 1;
}
