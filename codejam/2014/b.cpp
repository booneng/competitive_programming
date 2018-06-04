#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[1005], y[1005];

struct node {
  int parent;
  vector<pair<int, int> > children;
};

node nodes[1005];

// int maxSubtreeNodes(int current, int parent, vector<int>* adj) {
//   int a = 0, b = 0;
//   for (int i = 0; i < adj[current].size(); i++) {
//     int node = adj[current][i];
//     if (node == parent) continue;
//     int temp = maxSubtreeNodes(node, current, adj);
//     if (temp > b) {
//       b = temp;
//       if (b > a) swap(a, b);
//     }
//   }
//   if (a > 0 && b > 0) return 1 + a + b;
//   return 1;
// }

int maxSubtreeNodes(int current, int parent, vector<int>* adj) {
  nodes[current].children.clear();
  vector<pair<int, int> > children;
  int a = 0, b = 0;
  for (int i = 0; i < adj[current].size(); i++) {
    int node = adj[current][i];
    if (node == parent) continue;
    int temp = maxSubtreeNodes(node, current, adj);
    if (children.size() == 0 || temp > children[0].first) {
      children.push_back(make_pair(temp, node));
      sort(children.begin(), children.end());
      if (children.size() > 3) {
	children.erase(children.begin());
      }
    }
    if (temp > b) {
      b = temp;
      if (b > a) swap(a, b);
    }
  }
  nodes[current].parent = parent;
  nodes[current].children = children;
  if (a > 0 && b > 0){
    return 1 + a + b;
  }
  return 1;
}

void update(int in) {
  node current = nodes[in];
  int pi = current.parent;
  node parent = nodes[pi];
  int size = 1;
  for (int i = 0; i < parent.children.size(); i++) {
    int child = parent.children[i].second;
    if (child == in) continue;
    size += parent.children[i].first;
  }
  if (pi != 0) nodes[in].children.push_back(make_pair(size, pi));
  for (int i = 0; i < current.children.size(); i++) {
    update(current.children[i].second);
  }
}

void solve() {
  cin >> n;
  vector<int> adj[1005];
  for (int i = 1; i < n; i++) {
    cin >> x[i] >> y[i];
    adj[x[i]].push_back(y[i]);
    adj[y[i]].push_back(x[i]);
  }
  maxSubtreeNodes(1, 0, adj);
  update(1);
  // int min_deletions = n;
  // for (int root = 1; root <= n; root++) {
  //   min_deletions = min(min_deletions, n - maxSubtreeNodes(root, 0, adj));
  // }
  int max_size = 1;
  for (int i = 1; i <= n; i++) {
    node current = nodes[i];
    int size = 1;
    cout << i << ':' << endl;
    for (int j = 0; j < nodes[i].children.size(); j++) {
      cout << nodes[i].children[j].second << ' ' << nodes[i].children[j].first << endl;
      size += nodes[i].children[j].first;
    }
    max_size = max(max_size, size);
  }
  cout << n - max_size << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
