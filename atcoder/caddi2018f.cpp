#include <bits/stdc++.h>

using namespace std;

int grid[100005][100005];
const int mod = 998244353;

int mul(int a, int b) {
  long long x = a;
  long long y = b;
  return (x * y) % mod;
}

int add(int a, int b) {
  return (a + b) % mod;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    int r, c, v;
    cin >> r >> c >> v;
    r--;
    c--;
    grid[r][c] = v;
  }

  int multiplier = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (grid[i][j] > -1 && grid[j][i] > -1) {
        grid[i][j] = (grid[i][j] + grid[j][i]) % 2;
      }
      else if (grid[i][j] > -1 || grid[j][i] > -1) {
        grid[i][j] = -1;
      }
      else {
        grid[i][j] = -1;
        multiplier = mul(multiplier, 2);
      }
      if (j - i >= 3 && grid[i][j] == 1) {
        cout << 0;
        return 0;
      }
    }
  }




}