#include <bits/stdc++.h>

using namespace std;

int main() {
  int mod = 1000000007;
  int n, x, y;
  cin >> n >> x >> y;
  int minute_bound = x / y + 1;
  vector<pair<int, int>> shows(n);
  multiset<int> ends;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    shows[i] = {l, r};
  }

  sort(shows.begin(), shows.end());

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + ((long long)y * (shows[i].second - shows[i].first)) % mod) % mod;

    if (!ends.size()) {
      ans = (ans + x) % mod;
    }
    else {
      auto it = ends.lower_bound(shows[i].first);
      if (it == ends.begin() || *(--it) + minute_bound <= shows[i].first) {
	ans = (ans + x) % mod;
      }
      else {
	int remove = *it;
	ans = (ans + ((long long)y * (shows[i].first - remove)) % mod) % mod;
	ends.erase(it);
      }
    }
    ends.insert(shows[i].second);
  }

  cout << ans;
}
