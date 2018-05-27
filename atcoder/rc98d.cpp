#include <iostream>
#include <vector>

#define ll long long int

using namespace std;


int main() {
  ll n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  ll l = 0, r = 1;
  ll cur = a[0];
  for (; l < n; l++) {
    if (r == l) {
      cur += a[r];
      r++;
    }
    while ((a[r] & cur) == 0 && r < n) {
      cur += a[r];
      r++;
    }
    cur -= a[l];
    ans += r - l;
  }
  cout << ans;
}
