#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> subjects(n);

  for (int i = 0; i < n; i++) {
    int s, r;
    cin >> s >> r;
    subjects[i] = {s, r};
  }
  sort(subjects.begin(), subjects.end(), greater<pair<int, int>>());
  int prevs = 0;
  int cur = 0;
  int cnt = 0;
  vector<int> cnts(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int s = subjects[i].first;
    if (s == prevs) {
      cnt++;
      cur += subjects[i].second;
    }
    else {
      cnt = 1;
      cur = subjects[i].second;
      prevs = s;
    }
    if (cur > 0) cnts[cnt] += cur;
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    // cout << cnts[i] << ' ';
    ans = max(ans, cnts[i]);
  }
  // cout << endl;
  cout << ans;
}
