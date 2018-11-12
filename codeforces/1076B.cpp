#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2;
    return 0;
  }
  long long MAX = 100001;
  vector<bool> primes(MAX, true);
  long long smallest_prime = 0;
  for (long long int i = 2; i < MAX; i++) {
    if (!primes[i]) continue;
    if (n % i == 0) {
      smallest_prime = i;
      break;
    }
    long long int m = i * i;
    while (m < MAX) {
      primes[m] = false;
      m += i;
    }
  }
  if (smallest_prime == 0) {
    cout << 1;
  }
  else {
    cout << ((n - smallest_prime) / 2 + 1);
  }
}
