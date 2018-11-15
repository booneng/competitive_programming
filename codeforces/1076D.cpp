#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m <= k) {
    cout << m << endl;
    for (int i = 1; i <= m; i++) {
      cout << i << ' ';
    }
    return 0;
  }
  vector< vector< vector<long long> > > adj(n + 1);
  for (int i = 1; i <= m; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({w, y, i});
    adj[y].push_back({w, x, i});
  }
  auto comp = [](vector<long long>& bottom, vector<long long>& top) {
		return top[0] < bottom[0];
	      };
  priority_queue<vector<long long>, vector< vector<long long> >, decltype(comp)> pq(comp);
  vector<long long> dists(n + 1, numeric_limits<long long>::max());
  vector<int> in(n + 1);

  pq.push({0, 1, 0});
  dists[1] = 0;
  int nedges = 0;
  while (!pq.empty()) {
    long long d = pq.top()[0];
    long long p = pq.top()[1];
    pq.pop();
    if (d != dists[p]) continue;
    nedges++;
    if (nedges > k) break;
    for (auto e : adj[p]) {
      if ((d + e[0]) < dists[e[1]]) {
	dists[e[1]] = d + e[0];
	e[0] += d;
	in[e[1]] = e[2];
	pq.push(e);
      }
    }
  }
  vector<pair<long long, int>> vec;
  for (int i = 2; i <= n; i++) {
    vec.push_back({dists[i], in[i]});
  }
  sort(vec.begin(), vec.end());
  vector<int> edges;
  for (int i = 0; i < vec.size(); i++) {
    if (i == k) break;
    edges.push_back(vec[i].second);
  }
  cout << edges.size() << endl;
  for (int i : edges) {
    cout << i << ' ';
  }

}
