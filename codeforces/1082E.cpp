#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> ccnts(n + 1, 0);
  for (int i = 0; i < n; i++) {
    ccnts[i + 1] = ccnts[i];
    if (a[i] == c) ccnts[i + 1]++;
  }
  
  vector<vector<int>> segs(500001, vector<int>());
  vector<int> lst(500001, -1);
  for (int i = 0; i < n; i++) {
    segs[a[i]].push_back(ccnts[lst[a[i]] + 1] - ccnts[i]);
    lst[a[i]] = i;
    segs[a[i]].push_back(1);
  }

  int ans = 0;
  for (int i = 0; i < 500001; i++) {
    if (i == c) continue;
    int kad = 0;
    int cur = 0;
    for (int j = 0; j < segs[i].size(); j++) {
      cur = max(0, cur + segs[i][j]);
      kad = max(kad, cur);
      
    }
    ans = max(ans, kad);
  }
  cout << ccnts[n] + ans;
}
