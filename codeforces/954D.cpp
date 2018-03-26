#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int s_distances[1000];
int t_distances[1000];
class Nsk {
private:
  int n;
  vector<int> *adj;

public:
  Nsk(int n) {
    this->n = n;
    adj = new vector<int>[n + 1];
  }
  
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void bfs(int s, int* distances) {
    bool visited[n + 1];
    for (int i = 0; i < n + 1; i++) {
      visited[i] = false;
    }
    queue< pair<int, int> > q;
    q.push(make_pair(s, 0));
    visited[s] = true;
    while (!q.empty()) {
      pair<int, int> vd = q.front();
      q.pop();
      int v = vd.first;
      int d = vd.second;
      distances[v] = d;
      vector<int>::iterator i;
      for(i = adj[v].begin(); i != adj[v].end(); i++) {
	if(!visited[*i]) {
	  visited[*i] = true;
	  q.push(make_pair(*i, d + 1));
	}
      }
    }
  }

  bool checkAdj(int u, int v) {
    return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
  }
};

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  Nsk nsk(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    nsk.addEdge(u, v);
  }
  for (int i = 0; i < n + 1; i++) {
    s_distances[i] = 0;
    t_distances[i] = 0;
  }
  nsk.bfs(s, s_distances);
  nsk.bfs(t, t_distances);
  int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int min = (s_distances[i] + t_distances[j] > s_distances[j] + t_distances[i]) ? s_distances[j] + t_distances[i] : s_distances[i] + t_distances[j];
      if (min + 1 >= s_distances[t] && !nsk.checkAdj(i, j)) {
	count++;
      }
    }
  }
  cout << count;
}
