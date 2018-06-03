#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
vector<int> leaves;

void dfs(int v, int pr) {
  int deg = 0;
  for (int to : adj[v]) {
    if (to != pr) {
      deg++;
      dfs(to, v);
    }
  }
  if (!deg) {
    leaves.push_back(v);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int v = 0;
  int found = false;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() > 2) {
      if (found) {
	cout << "No";
	return 0;
      }
      v = i;
      found = true;
    }
  }

  dfs(v, -1);
  cout << "Yes" << endl;
  cout << leaves.size() << endl;
  for (int i : leaves) {
    cout << v + 1 << ' ' << i + 1 << endl;
  }
}
