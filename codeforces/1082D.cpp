#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    a[i - 1] = {tmp, i};
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  int index = 0;
  vector<pair<int, int>> edges;
  while (index < n - 1 && a[index].first >= 1) {
    edges.push_back({a[index].second, a[index + 1].second});
    a[index].first--;
    a[index + 1].first--;
    index++;
  }
  int diam = edges.size();
  int fend = edges.size();
  if (index <= n - 2) {
    diam++;
  }
  index++;
  int findex = 0;
  while (index < n && findex < fend) {
    if (a[findex].first == 0) {
      findex++;
    }
    else {
      edges.push_back({a[index].second, a[findex].second});
      index++;
      a[findex].first--;
    }
  }

  if (index < n) cout << "NO";
  else {
    cout << "YES " << diam << endl;
    cout << edges.size() << endl;
    for (auto& edge : edges) {
      cout << edge.first << ' ' << edge.second << endl;
    }

  }
  
}
