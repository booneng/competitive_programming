#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> switch_lamp[n];
  vector<int> counts(m, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
	switch_lamp[i].push_back(j);
	counts[j]++;
      }
    }
  }

  bool ans;
  for (int i = 0; i < n; i++) {
    ans = true;
    for (int lamp : switch_lamp[i]) {
      if (counts[lamp] == 1) {
	ans = false;
	break;
      }
    }
    if (ans) break;
  }

  cout << (ans ? "YES" : "NO");
}
