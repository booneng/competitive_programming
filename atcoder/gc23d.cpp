#include <iostream>

#define ll long long int

using namespace std;

ll n;
ll s;
ll x[100005];
ll p[100005];
ll ans;

void get_ans(ll left, ll right) {
  while (x[left] < s && x[right] > s) {
    ans += x[right] - x[left];
    if (p[left] >= p[right]) {
      while (p[left] >= p[right] && x[left] < s) {
	p[left] += p[right];
	right--;
      }
    }
    else {
      while (p[right] > p[left] && x[right] > s) {
	p[right] += p[left];
	left++;
      }
    }
  }
  if (x[left] >= s) {
    ans += x[right] - s;
    return;
  }
  if (x[right] <= s) {
    ans += s - x[left];
    return;
  }
}

int main() {
  cin >> n >> s;
  for (ll i = 0; i < n; i++) {
    cin >> x[i] >> p[i];
  }
  ans = 0;
  get_ans(0, n - 1);
  cout << ans;
}
