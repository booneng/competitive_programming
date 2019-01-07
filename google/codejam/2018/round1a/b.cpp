
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int r, c;
    ll b;
    cin >> r >> b >> c;
    ll m[1005];
    ll s[1005];
    ll p[1005];
    ll max_s = 0;
    ll max_p = 0;
    for (int j = 0; j < c; j++) {
      cin >> m[j] >> s[j] >> p[j];
      max_s = max(max_s, s[j]);
      max_p = max(max_p, p[j]);
    }
    ll left = 1;
    ll right = max_s * b + max_p;
    ll ans = right;
    while (left <= right) {
      ll mid = (right + left) / 2;
      vector<ll> capacities;
      for (int j = 0; j < c; j++) {
	ll c = min(m[j], (mid - p[j]) / s[j]);
        ll capacity = max(0LL, c);
	capacities.push_back(capacity);
      }
      sort(capacities.begin(), capacities.end(), greater<ll>());
      ll sum = 0;
      for (int j = 0; j < r; j++) {
	sum += capacities[j];
      }
      if (sum < b) {
	left = mid + 1;
      }
      else if (sum >= b) {
	right = mid - 1, ans = mid;
      }
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
}
