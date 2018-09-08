#include <iostream>
#include <cmath>

using namespace std;

#define ll long long int

int main() {
  ll n, k;
  cin >> n >> k;
  ll x[n];
  for (ll i = 0; i < n; i++) cin >> x[i];
  ll min_d = 2e18;
  for (ll i = 0; i < n - k + 1; i++) {
    ll d = x[i + k - 1] - x[i] + min(abs(x[i]), abs(x[i + k - 1]));
    if (d < min_d) {
      min_d = d;
    }
  }
  cout << min_d;
}
