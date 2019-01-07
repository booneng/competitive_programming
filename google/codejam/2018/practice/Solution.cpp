#include <iostream>
#define ll long long int
using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    ll n, k;
    cin >> n >> k;
    ll count = 1;
    while (k > 1) {
      if (k % 2 == 0) n /= 2;
      else n = (n - 1) / 2;
      k -= 1;
      k = (k + 1) / 2;
    }
    ll l = (n - 1) / 2;
    ll r = n / 2;
    cout << r << ' ' << l << endl;
  }
}
