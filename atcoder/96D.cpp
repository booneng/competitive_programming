#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

ll x[100005];
ll v[100005];
ll sums[100005];
ll maxes[100005];
ll sums2[100005];
ll maxes2[100005];
ll n, c;

int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
  }
  ll ans = 0;
  ll cals = 0;
  for (int i = 1; i <= n; i++) {
    cals += v[i];
    ans = max(ans, cals - x[i]);
  }
  cals = 0;
  for (int i = n; i >= 1; i--) {
    cals += v[i];
    ans = max(ans, cals - (c - x[i]));
  }
  sums[0] = 0;
  maxes[0] = 0;
  // xes[0] = 0;

  for (int i = 1; i <= n; i++) {
    sums[i] = sums[i - 1] + v[i];
    maxes[i] = max(maxes[i - 1], sums[i] - x[i]);
    // xes[i] = maxes[i] > maxes[i - 1] ? x[i] : xes[i - 1];
  }
  
  sums2[n + 1] = 0;
  maxes2[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    sums2[i] = sums2[i + 1] + v[i];
    maxes2[i] = max(maxes2[i + 1], sums2[i] - (c - x[i]));
  }

  for (int i = 1; i <= n; i++) {
    ans = max(ans, maxes[i] + maxes2[i + 1] - x[i]);
  }
  for (int i = n; i >= 1; i--) {
    ans = max(ans, maxes2[i] + maxes[i - 1] - (c - x[i]));
  }

  // for (int i = 1; i <= n; i++) {
  //   ll left_sum = sums[n] - sums[i - 1] - (c - x[i]);
  //   ll dbld = (c - x[i] > xes[i - 1]) ? xes[i - 1] : c - x[i];
  //   ans = max(ans, maxes[i - 1] + left_sum - dbld);
  // }
  
  // for (int i = 0; i < n; i++) {
  //   for (int j = n - 1; j > i; j--) {
  //     ll cals = 0;
  //     for (int k = 0; k <= i; k++) {
  // 	cals += v[k];
  //     }
  //     for (int k = n - 1; k >= j; k--) {
  // 	cals += v[k];
  //     }
  //     ll dist = min(2 * x[i] + c - x[j], 2 * (c - x[j]) + x[i]);
  //     ans = max(ans, cals - dist);
  //   }
  // }
  cout << ans;
}
