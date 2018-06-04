#include <iostream>
#include <cmath>

#define ll long long int

using namespace std;

void print_bin(ll x) {
  while (x > 0) {
    cout << x % 2;
    x /= 2;
  }
}

int main() {
  int tc;
  cin >> tc;
  cout << fixed;
  cout << "Case #1:" << endl;
  int n, j;
  cin >> n >> j;
  ll factor = pow(2, n / 2) + 1;
  ll base = pow(2, n / 2 - 1) + 1;
  ll factors[11];
  for (int i = 2; i <= 10; i++) {
    factors[i] = pow(i, n / 2) + 1;
  }
  for (int i = 0; i < j; i++) {
    print_bin((base + i * 2) * factor);
    for (int k = 2; k <= 10; k++) {
      cout << ' ' << factors[k];
    }
    cout << endl;
  }
}
