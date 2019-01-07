#include <bits/stdc++.h>

using namespace std;

long long solve() {
  int v, e;
  cin >> v >> e;
  vector<bool> used(v, false);
  vector<bool> zero(v, false);
  vector<pair<int, int>> edges;
  vector<int> a(e);
  vector<int> b(e);
  vector<int> l(e);
  for (int i = 0; i < e; i++) {
    cin >> a[i] >> b[i] >> l[i];
    a[i]--;
    b[i]--;
    if (l[i] == 0) {
      zero[a[i]] = true;
      zero[b[i]] = true;
    }
    edges.push_back({l[i], i});
  }
  sort(edges.begin(), edges.end());
  unsigned long long ans = 1;
  for (auto& e : edges) {
    int v1 = a[e.second];
    int v2 = b[e.second];
    if (!used[v1] && !used[v2]) {
      ans *= 2;
    }
    else if (used[v1] && zero[v1] && !used[v2]) {
      ans *= 2;
    }
    else if (used[v2] && zero[v2] && !used[v1]) {
      ans *= 2;
    }
    used[v1] = true;
    used[v2] = true;
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }

}
