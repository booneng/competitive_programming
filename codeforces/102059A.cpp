#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int colors[N];
int color_cnts[N];
int parents[N];
int nodes[N];
vector<int> adj[N];
int n;

void traverse(int i, int p) {
  parents[i] = p;
  for (int child : adj[i]) {
    if (child == p) continue;
    traverse(child, i);
  }
}

void color(int i, int c) {
  if (i == 1) return;
  int current = nodes[i];

  if (current > 0) {
    color_cnts[colors[current]]--;
    colors[current]--;
    color_cnts[colors[current]]++;
  }

  nodes[i] = c;

  color_cnts[colors[c]]--;
  colors[c]++;
  color_cnts[colors[c]]++;
  color(parents[i], c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, C, Q;
  cin >> n >> C >> Q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  color_cnts[0] = C;
  traverse(1, 1);
  for (int i = 0; i < Q; i++) {
    int u, c, m;
    cin >> u >> c >> m;
    color(u, c);
    cout << color_cnts[m] << endl;
  }

}