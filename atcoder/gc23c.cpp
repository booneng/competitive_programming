#include <iostream>

#define ll long long int
using namespace std;

ll mod = 1000000007;

ll factorials[1000005];
ll inv[1000005];

ll mod_pow(ll k, ll pow) {
  ll ans = 1;
  while (pow > 0) {
    if (pow & 1) ans = ans * k % mod;
    k = k * k % mod;
    pow >>= 1;
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;
  factorials[0] = 1;
  inv[0] = 1;

  for (int i = 1; i < 1000005; i++) {
    factorials[i] = (factorials[i - 1] * i) % mod;
    inv[i] = (inv[i - 1] * mod_pow(i, mod - 2)) % mod;
  }
  
  ll min_score = (n + 1) / 2;
  ll max_score = n - 1;
  ll ans = 0;
  ll prev = 0;
  for (int i = min_score; i <= max_score; i++) {
    ll cnk = ((factorials[i - 1] * inv[n - 1 - i] % mod) * inv[2 * i - n] % mod) % mod;
    ll add = (cnk * factorials[i] % mod) * factorials[n - 1 - i] % mod;
    ans = (ans + (((add - prev + mod) % mod) * i) % mod) % mod;
    prev = add;
  }
  cout << ans;
}
