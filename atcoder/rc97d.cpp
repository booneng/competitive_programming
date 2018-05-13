#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int m, n;
int p[100005];
vector<int> adj[100005];
bool visited[100005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) visited[i] = false;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    set<int> indices;
    set<int> values;
    queue<int> dfs;
    dfs.push(i);
    indices.insert(i);
    while (!dfs.empty()) {
      int top = dfs.front();
      dfs.pop();
      visited[top] = true;
      indices.insert(top);
      values.insert(p[top]);
      for (int i = 0; i < adj[top].size(); i++) {
	int index = adj[top][i];
	if (visited[index]) continue;
	dfs.push(index);
      }
    }
    set<int>::iterator it = indices.begin();
    for (; it != indices.end(); it++) {
      if (values.find(*it) != values.end()) ans++;
    }
  }
  cout << ans;
  
}
