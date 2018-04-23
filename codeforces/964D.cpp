#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  set<int> adj[200005];
  int n;
  cin >> n;
  int n_edges = 0;
  set<int> vertices;
  for (int i = 1; i <= n; i++) {
    vertices.insert(i);
    int temp;
    cin >> temp;
    if (temp != 0) {
      adj[i].insert(temp);
      adj[temp].insert(i);
      n_edges++;
    }
  }
  bool done = false;
  int removed = 0;
  vector<int> rorder;
  while(!done) {
    done = true;
    for (int i = 1; i <= n; i++) {
      if (adj[i].size() > 0 && adj[i].size() % 2 == 0) {
	removed += adj[i].size();
	rorder.push_back(i);
	done = false;
	for (auto e: adj[i]) {
	  adj[e].erase(i);
	}
	adj[i].clear();
      }
    }
  }
  if (removed == n_edges) {
    cout << "YES" << endl;
    for (auto v: rorder) {
      cout << v << endl;
      vertices.erase(v);
    }
    for (auto v: vertices) {
      cout << v << endl;
    }
  }
  else {
    cout << "NO" << endl;
  }
}
