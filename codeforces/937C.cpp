#include <iostream>

#define ll long long int
using namespace std;

int main() {
  cout << fixed;
  ll k, d, t;
  cin >> k >> d >> t;
  ll n = 1;
  while (n * d < k) {
    n++;
  }
  ll round = 2 * k + (n * d - k);
  ll rounds = 0;
  while ((round * (rounds + 1)) < (2 * t)) {
    rounds++;
  }
  double ans = rounds * n * d;
  double remaining = (double)1 - rounds * (((double)k / t) + (double)(n * d - k) / (2 * t));
  if (remaining < (double) k / t) {
    ans += remaining * t;
  }
  else {
    ans += t;
    cout << ans;
    ans += (remaining - ((double)k / t)) * 2 * t;
  }
  cout << ans;
}
