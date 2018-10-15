#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int main() {
  ll mod = 1000000007;
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> probs(n);
  probs[0] = 0;
  for (int i = 1; i < n; i++) {
    ll tmp = mod - 2;
    probs[i] = 1;
    ll base = i + 1;
    while (tmp > 0) {
      if (tmp & 1) probs[i] = (probs[i] * base) % mod;
      base = (base * base) % mod;
      tmp >>= 1;
    }
  }

  vector<ll> sumprobs(n);
  sumprobs[0] = 0;
  for (int i = 1; i < n; i++) {
    sumprobs[i] = (probs[i] + sumprobs[i - 1]) % mod;
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll b = (a[i] * sumprobs[i]) % mod;
    b = (b + a[i] * sumprobs[n - 1 - i]) % mod;
    b = (b + a[i]) % mod;
    ans = (ans + b) % mod;
  }

  for (int i = 0; i < n; i++) {
    ans = (ans * (i + 1)) % mod;
  }
  cout << ans;
}
