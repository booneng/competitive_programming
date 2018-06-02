#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    vector<int> subs;
    vector<int> full;
    for (int j = 0; j < n; j++) {
      if (a[j] >= x) {
	subs.emplace_back(a[j]);
      }
      else {
	if (subs.size() >= k) {
	  sort(subs.begin(), subs.end());
	  for (int l = 0; l < subs.size() - k + 1; l++) {
	    full.emplace_back(subs[l]);
	  }
	}
	subs.clear();
      }
    }
    if (subs.size() >= k) {
      sort(subs.begin(), subs.end());
      for (int l = 0; l < subs.size() - k + 1; l++) {
	full.emplace_back(subs[l]);
      }
    }
    sort(full.begin(), full.end());
    if (full.size() >= q) {
      ans = min(ans, full[q - 1] - x);
    }
  }
  cout << ans;
}
