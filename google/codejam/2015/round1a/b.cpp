#include <iostream>
#include <cmath>

#define ll long long int
using namespace std;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int b, n;
    cin >> b >> n;
    ll m[1005];
    ll slowest = 0;
    for (int i = 0; i < b; i++) {
      cin >> m[i];
      slowest = max(slowest, m[i]);
    }
    ll max_t = slowest * n;
    ll left = 0;
    ll right = max_t;
    while (left < right) {
      ll mid = (left + right) / 2;
      ll served_customers = 0;
      for (int i = 0; i < b; i++) {
	served_customers += mid / m[i] + 1;
      }
      if (served_customers < n) {
	left = mid + 1;
      }
      else {
	right = mid;
      }
    }
    int barber = -1;
    if (left == 0) barber = n;
    else {
      int rem1 = 0;
      int rem2 = 0;
      for (int i = 0; i < b; i++) {
	rem1 += (left - 1)/ m[i] + 1;
      }

      int pos = n - rem1;
      for (int i = 0; i < b; i++) {
	if (left % m[i] == 0) {
	  pos--;
	  if (pos == 0) {
	    barber = i + 1;
	    break;
	  }
	}
      }
    }
    cout << "Case #" << t << ": " << barber << endl;
  }

}
