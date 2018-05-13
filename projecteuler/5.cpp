#include <iostream>

#define ll long long int

using namespace std;

ll hcf(ll a, ll b) {
  while (a != b) {
    if (a > b) a-= b;
    else b -= a;
  }
  return a;
}

ll lcm(ll a, ll b) {
  return a * b / hcf(a, b);
}

int main() {
  ll ans = 1;
  for (ll i = 1; i <= 20; i++) {
    ans = lcm(ans, i);
  }
  cout << ans;
}
