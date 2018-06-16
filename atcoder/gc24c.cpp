#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (a[0] > 0) {
    cout << -1;
    return 0;
  }

  ll ans = 0;
  ll count = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] > 1) {
      cout << -1;
      return 0;
    }
    else if (a[i] - a[i - 1] == 1) {
      count++;
    }
    else {
      ans += count;
      count = a[i];
    }
  }
  ans += count;
  cout << ans;
}
