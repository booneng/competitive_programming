#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> segments;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      segments.push_back({{l, r}, i});
    }
    sort(segments.begin(), segments.end());

    vector<int> groups(n, 2);
    groups[segments[0].second] = 1;
    bool can = false;
    int pr = segments[0].first.second;
    for (int i = 1; i < n; i++) {
      if (segments[i].first.first <= pr) {
        groups[segments[i].second] = 1;
        pr = max(pr, segments[i].first.second);
      }
      else {
        can = true;
        break;
      }
    }
    if (!can) cout << -1;
    else {
      for (int i : groups) cout << i << ' ';
    }
    cout << endl;
  }
}