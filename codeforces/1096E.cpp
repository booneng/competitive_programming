#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int mod = 998244353;
int rfac[N];
int fac[N];

int mul(int a, int b) {
  long long x = a;
  long long y = b;
  return (x * y) % mod;
}

int add(int a, int b) {
  a += b;
  if (a >= mod) a-= mod;
  else if (a < 0) a += mod;
  return a;
}

int nck(int n, int k) {
  if (n == k) return 1;
  if (n < k || k < 0) return 0;
  return mul(fac[n], mul(rfac[n - k], rfac[k]));
}

int inv(int k) {
  return mul(fac[k - 1], rfac[k]);
}

int modpow(int a, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = mul(ans, a);
    }
    a = mul(a, a);
    p >>= 1;
  }
  return ans;
}

int g(int s, int p, int m) {
  int res = 0;
  for (int i = 0; i <= p; i++) {
    int sign = (i % 2) ? mod - 1 : 1;
    res = add(res, mul(sign, mul(nck(p, i), nck(s + p - 1 - i * (m + 1), p - 1))));
  }
  return res;
}


int main() {
  int p, s, r;
  cin >> p >> s >> r;
  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  rfac[N - 1] = modpow(fac[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    rfac[i] = mul(rfac[i + 1], i + 1);
  }

  int bottom = nck(s - r + p - 1, p - 1);
  int top = 0;

  for (int i = r; i <= s; i++) {
    for (int q = 1; q <= p; q++) {
      top = add(top, mul(nck(p - 1, q - 1), mul(inv(q), g(s - q * i, p - q, i - 1))));
    }
  }
  cout << mul(top, modpow(bottom, mod - 2));
}