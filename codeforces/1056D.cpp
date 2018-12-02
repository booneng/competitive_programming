#include <bits/stdc++.h>

using namespace std;

int traverse(int index, vector<int>& ans, vector<vector<int>>& adj, int parent) {
  int cnt = 0;
  for (int child : adj[index]) {
    if (child == parent) continue;
    cnt++;
    traverse(child, ans, adj, index);
    ans[index] += ans[child];
  }

  if (cnt == 0) {
    ans[index] = 1;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }

  vector<int> ans(n + 1, 0);
  traverse(1, ans, adj, 0);
  sort(ans.begin(), ans.end());
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }

}
