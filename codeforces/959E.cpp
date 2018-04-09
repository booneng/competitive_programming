#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define ll long long int

using namespace std;

ll solve(ll n) {
  if (n == 1) return 0;
  return (n / 2) + 2 * solve((n + 1) / 2);
}
int main() {
  ll n;
  cin >> n;
  cout << solve(n);
}
