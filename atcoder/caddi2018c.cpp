#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;
  long long i = 2;
  long long ans = 1;
  while (i * i <= p) {
    int power = 0;
    while (p % i == 0) {
      p /= i;
      power++;
    }
    long long mul = 1;
    for (int j = 0; j < power / n; j++) mul *= i;
    ans *= mul;
    i++;
  }
  if (p > 1) {
    if (n == 1) ans *= p;
  }
  cout << ans;

}