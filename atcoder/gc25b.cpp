#include <iostream>

#define ll long long int

const ll MOD = 998244353;

ll facs[300005];
ll invs[300005];

using namespace std;

ll mod_pow(ll k, ll pow) {
  ll ans = 1;
  while (pow > 0) {
    if (pow & 1) ans = ans * k % MOD;
    k = k * k % MOD;
    pow >>= 1;
  }
  return ans;
}

int main() {
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  invs[0] = 1;
  facs[0] = 1;
  for (int i = 1; i <= n; i++) {
    facs[i] = facs[i - 1] * i % MOD;
    invs[i] = (invs[i - 1] * mod_pow(i, MOD - 2)) % MOD;
  }
  ll ans = 0;
  for (ll na = 0; na <= n; na++) {
    if (k < na * a) break;
    if ((k - na * a) % b == 0) {
      ll nb = (k - (na * a)) / b;
      if (nb <= n) {
	ll nca = (facs[n] * ((invs[n - na] * invs[na]) % MOD)) % MOD;
	ll ncb = (facs[n] * ((invs[n - nb] * invs[nb]) % MOD)) % MOD;
	ll ways = (nca * ncb) % MOD;
	ans = (ans + ways) % MOD;
      }
    }
  }
  cout << ans;
}
