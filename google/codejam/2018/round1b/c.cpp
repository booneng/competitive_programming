#include <iostream>
#include <algorithm>

#define ll long long int
using namespace std;

int m;
ll g[105];
ll tmp[105];
ll r1[105];
ll r2[105];
ll recipes[105][105];
ll recipes_o[105][105];

int find_neg() {
  for (int i = 1; i <= m; i++) {
    if (tmp[i] < 0) return i;
  }
  return m + 1;
}

bool can(ll l) {
  for (int i = 1; i <= m; i++) {
    tmp[i] = g[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      recipes[i][j] = recipes_o[i][j];
    }
  }
  tmp[1] -= l;
  for (int i = find_neg(); i <= m; i = find_neg()) {
    if (recipes[i][i] > 0) return false;
    for (int j = 1; j <= m; j++) {
      tmp[j] += recipes[i][j] * tmp[i];
    }
    
    for (int j = 1; j <= m; j++) {
      if (recipes[j][i] > 0) {
	for (int k = 1; k <= m; k++) {
	  recipes[j][k] += recipes[j][i] * recipes[i][k];
	}
	recipes[j][i] = 0;
      }
    }
    tmp[i] = 0;
  }
  return true;
}

void solve() {
  cin >> m;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      recipes_o[i][j] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> r1[i] >> r2[i];
    recipes_o[i][r1[i]] = recipes_o[i][r2[i]] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> g[i];
  }
  ll left = 0;
  ll right = 1000000000000;
  while (left <= right) {
    ll mid = 0.5 * (left + right);
    if (can(mid)) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  cout << left - 1 << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
