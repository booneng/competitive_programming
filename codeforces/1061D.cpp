#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
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
    auto it = ends.lower_bound(shows[i].first);
    if (!ends.size() || it == ends.begin() || (*--it) + minute_bound <= shows[i].first) {
      ans = (ans + x) % mod;
    }
    else {
      ans = (ans + ((long long)y * (shows[i].first - *it)) % mod) % mod;
      ends.erase(it);
    }
    ends.insert(shows[i].second);
  }

  cout << ans;
}
