#include <iostream>

#define ll long long int

using namespace std;

ll n, m;
ll a[200005];
ll b[200005];
ll sums[200005];
ll val;

ll find_dorm(ll left, ll right) {
  while (left < right) {
    ll mid = (left + right) / 2;
    if (val > sums[mid]) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  return left;
}

int main() {
  cin >> n >> m;
  cin >> a[0];
  sums[0] = a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    sums[i] = sums[i - 1] + a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < m; i++) {
    // int dorm = 0;
    // for (int j = 0; j < n; j++) {
    //   if (b[i] <= sums[j]) break;
    //   dorm = j + 1;
    // }
    val = b[i];
    ll dorm = find_dorm(0, n - 1);
    if (dorm == 0) {
      cout << dorm + 1 << ' ' << b[i] << endl;
    }
    else {
      cout << dorm + 1 << ' ' << b[i] - sums[dorm - 1] << endl;
    }
  }
  
  
}
