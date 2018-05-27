#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
  ll n, k, l;
  cin >> n >> k >> l;
  ll m = n * k;
  vector<ll> a(m);
  for (ll i = 0; i < m; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  ll highest = a[0] + l;
  auto it = upper_bound(a.begin(), a.end(), highest);
  if (it - a.begin() < n) {
    cout << 0;
  }
  else {
    ll volume = 0;
    int until = it - a.begin();
    ll rem = n;
    for (int i = 0; i < until; i++) {
      if (until - i <= rem) {
	volume += a[i];
      }
      else if (i % k == 0) {
	volume += a[i];
	rem--;
      }
    }
    cout << volume;
  }
}
