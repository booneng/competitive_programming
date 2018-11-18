#include <bits/stdc++.h>

using namespace std;

long long facs[200005];
long long inv[200005];
const long long mod = 1000000007;
long long twop[100005];


long long modinv(long long num) {
  long long power = mod - 2;
  long long base = num;
  long long ans = 1;
  while (power) {
    if (power & 1) {
      ans = (ans * base) % mod;
    }
    base = (base * base) % mod;
    power >>= 1;
  }
  return ans;
}

long long mul(long long a, long long b) {
  long long tmp = a * b;
  if (tmp < 0) tmp += mod;
  return tmp % mod;
}

long long add(long long a, long long b) {
  long long tmp = a + b;
  if (tmp < 0) tmp += mod;
  return tmp % mod;
}

long long sub(long long a, long long b) {
  long long tmp = a - b;
  if (tmp < 0) tmp += mod;
  return tmp % mod;
}

long long choose(long long n, long long k) {
  return mul(mul(facs[n], inv[k]), inv[n - k]);
}

long long solve() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  long long sign = 1;
  for (int i = 0; i <= m; i++) {
    long long addition = mul(choose(2 * n - i, i), facs[i]);
    addition = mul(addition, twop[i]);
    addition = mul(addition, facs[2 * (n - i)]);
    addition = mul(addition, choose(m, i));
    addition = mul(sign, addition);
    ans = add(ans, addition);
    sign *= -1;
  }
  return ans;
}


int main() {
  facs[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    facs[i] = (facs[i - 1] * i) % mod;
    inv[i] = modinv(facs[i]);
  }
  twop[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    twop[i] = (twop[i - 1] * 2) % mod;
  }
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }

}
