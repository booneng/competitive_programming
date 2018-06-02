#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int unique_ij[n][n + 1];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      string subs = s.substr(i, j - i);
      set<char> u;
      for (char c : subs) {
	u.insert(c);
      }
      unique_ij[i][j] = u.size();
    }
  }

  for (int i = 0; i < m; i++) {
    int x, y, len;
    cin >> x >> y >> len;
    x--;
    y--;
    if (unique_ij[x][x + len] == unique_ij[y][y + len]) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}
