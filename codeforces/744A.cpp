#include <bits/stdc++.h>

using namespace std;

int root[1005];
int size[1005];
bool country[1005];

int find(int i) {
  if (i != root[i]) root[i] = find(root[i]);
  return root[i];
}

int maxEdges(int csize) {
  return csize * (csize - 1) / 2;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    root[i] = i;
  }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    c--;
    country[c] = true;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int paru = find(u);
    int parv = find(v);
    root[parv] = paru;
  }

  for (int i = 0; i < n; i++) {
    size[find(i)]++;
  }

  int largest_country = 0;
  int total_edges = 0;
  int remaining = n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (country[i]) {
      int par = find(i);
      largest_country = max(largest_country, size[par]);
      remaining -= size[par];
      ans += maxEdges(size[par]);
    }
  }
  ans -= maxEdges(largest_country);
  ans += maxEdges(largest_country + remaining);
  ans -= m;
  cout << ans;
}
