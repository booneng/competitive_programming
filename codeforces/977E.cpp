#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[200005];
bool visited[200005];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) visited[i] = false;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    queue<int> cc;
    cc.push(i);
    bool can = true;
    while (!cc.empty()) {
      int top = cc.front();
      visited[top] = true;
      if (adj[top].size() != 2) can = false;
      cc.pop();
      for (int j = 0; j < adj[top].size(); j++) {
	int next = adj[top][j];
	if (visited[next]) continue;
	cc.push(next);
      }
    }
    if (can) ans++;
  }
  cout << ans;
}
