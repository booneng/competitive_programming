#include <iostream>
#include <cmath>

#define ll long long int

using namespace std;

int main() {
  ll n, l;
  cin >> n >> l;
  ll c[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    c[i + 1] = min(c[i + 1], 2 * c[i]);
  }

  ll ans = (ll)4e18;
  ll sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int need = l / (1 << i);
    sum += (ll) need * c[i];
    l -= need << i;
    ans = min(ans, sum + (l > 0) * c[i]);
  }
  cout << ans;
}
