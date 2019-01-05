#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj(100005);
vector<int> s(100005);
vector<int> a(100005);
vector<int> p(100005);

bool can = true;

void traverse(int i) {
  if (s[i] == -1) {
    if (adj[i].size()) {
      int min_children = 1000000000;
      for (int node : adj[i]) {
        min_children = min(s[node], min_children);
      }
      if (min_children < s[p[i]]) {
        can = false;
      }
      s[i] = min_children;
    }
    else {
      s[i] = s[p[i]];
    }
  }
  for (int node : adj[i]) {
    traverse(node);
    a[node] = s[node] - s[i];
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    adj[p[i]].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  a[0] = s[0];
  traverse(0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  if (!can) cout << -1;
  else cout << ans;
}