#include <iostream>
#include <map>
#include <set>
#define ll long long int
using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    ll n, k;
    cin >> n >> k;
    map<ll, ll> c;
    set<ll> s;
    s.insert(n);
    c[n] = 1;
    ll p = 0;
    ll x0 = 0, x1 = 0;
    while (p < k) {
      ll x = *s.rbegin();
      x1 = (x - 1) / 2;
      if (x % 2 == 0) x0 = x1 + 1;
      else x0 = x1;
      ll count = c[x];
      p = p + count;
      s.erase(x);
      c[x0] += count;
      c[x1] += count;
    }
    cout << x0 << ' ' << x1 << endl;
  }
}
