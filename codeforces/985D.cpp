#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
  ll n, h;
  cin >> n >> h;
  ll k = (-1.0 + sqrt(1 + 8 * n)) / 2;
  ll used = k * k - (k - 1) * k / 2;
  if (k > h) {
    k = sqrt(n + (h * h - h) / 2);
    used = k * k - (h - 1) * h / 2;
  }
  ll tmp = n - used;
  ll add = tmp % k ? tmp / k + 1 : tmp / k;
  add = max(add, 0LL);
  cout << 2 * k - min(h, k) + add;
}
