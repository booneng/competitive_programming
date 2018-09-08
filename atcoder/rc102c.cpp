#include <iostream>

#define ll long long int
using namespace std;

int main() {
  ll n, k;
  cin >> n >> k;
  if (k % 2) {
    ll i = k;
    ll count = 0;
    while (i <= n) {
      count++;
      i += k;
    }
    ll ans = count + count * (count - 1) * (count - 2) + 3 * count * (count - 1);
    cout << ans;
  }
  else {
    ll i = k;
    ll count = 0;
    while (i <= n) {
      count++;
      i += k;
    }
    ll ans = count + count * (count - 1) * (count - 2) + 3 * count * (count - 1);
    i = k / 2;
    count = 0;
    while (i <= n) {
      count++;
      i += k;
    }
    ans += count + count * (count - 1) * (count - 2) + 3 * count * (count - 1);
    cout << ans;
  }
}
