#include <bits/stdc++.h>

using namespace std;


int main() {
  int n, m, p;
  cin >> n >> m >> p;

  int s[p + 1];
  for (int i = 1; i <= p; i++) {
    cin >> s[i];
  }

  vector<string> grid(n);
  queue<pair<int, int>> q[10];
  vector<int> scores(10, 0);

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      char c = grid[i][j];
      if (c <= '9' && c >= '1') {
        scores[c - '0']++;
        q[c - '0'].push({i, j});
      }
    }
  }

  vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (true) {
    bool finished = true;
    for (int i = 1; i <= p; i++) {

      for (int j = 0; j < s[i]; j++) {
        int cnt = q[i].size();
        if (cnt == 0) break;
        for (int k = 0; k < cnt; k++) {
          auto cur = q[i].front();
          q[i].pop();
          for (auto move : moves) {
            int row = cur.first + move.first;
            int col = cur.second + move.second;
            if (row < 0 || row >= n || col < 0 || col >= m) continue;
            if (grid[row][col] == '.') {
              grid[row][col] = '0' + i;
              scores[i]++;
              finished = false;
              q[i].push({row, col});
            }
          }
        }
      }

    }
    if (finished) break;
  }

  for (int i = 1; i <= p; i++) {
    cout << scores[i] << ' ';
  }
}