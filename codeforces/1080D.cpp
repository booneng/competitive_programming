#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  vector<long long> sumFourPow;
  long long cur = 1;
  long long fourpow = 4;
  sumFourPow.push_back(0);
  while (cur <= 1e18) {
    sumFourPow.push_back(cur);
    cur += fourpow;
    fourpow *= 4;
  }
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if ((n == 2 && k == 3) || (n < 31 && k > sumFourPow[n])) {
      cout << "NO" << endl;
      continue;
    }
    long long splittable = 1;
    while (k >= splittable && n > 0) {
      k -= splittable;
      splittable = splittable * 2 + 1;
      n--;
    }

    cout << "YES " << n << endl;
  }
}
