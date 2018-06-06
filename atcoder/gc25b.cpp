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

ll get_ways(ll n, ll na, ll nb) {
  ll nc = min(na, nb);
  ll res = 0;
  for (ll ngreen = 0; ngreen <= nc; ngreen++) {
    ll nred = na - ngreen;
    ll nblue = nb - ngreen;
    if (ngreen + nred + nblue <= n) {
      ll perms = (facs[n] * invs[n - (ngreen + nred + nblue)]) % MOD;
      ll reps = (((invs[ngreen] * invs[nred]) % MOD) * invs[nblue]) % MOD;
      ll add = (perms * reps) % MOD;
      res = (res + add) % MOD;
    }
  }
  return res;
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
  for (ll na = 0; na < n; na++) {
    if (k < na * a) break;
    if ((k - na * a) % b == 0) {
      ll nb = (k - (na * a)) / b;
      ll ways = get_ways(n, na, nb);
      ans = (ans + ways) % MOD;
    }
  }
  cout << ans;
}
