#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string letters = "ACTG";
  vector<string> board(n);
  for (int i = 0; i < n; i++) cin >> board[i];
  vector<string> copy_board = board;
  vector<string> ans;

  int min_total_changes = n * m;
  for (char c1 : letters) {
    for (char c2 : letters) {
      if (c2 <= c1) continue;
      for (char c3 : letters) {
        if (c1 == c3 || c2 == c3) continue;
        for (char c4 : letters) {
          if (c1 == c4 || c2 == c4 || c4 <= c3) continue;
          vector<vector<char>> cs = {{c1, c2}, {c3, c4}};
          int total_changes = 0;
          for (int i = 0; i < n; i++) {
            int min_row_changes = m + 1;
            for (int order = 0; order < 2; order++) {
              int row_changes = 0;
              string tmp(m, '.');
              for (int j = 0; j < m; j++) {
                tmp[j] = cs[i % 2][(j + order) % 2];
                if (tmp[j] != board[i][j]) {
                  row_changes++;
                }
              }
              if (row_changes < min_row_changes) {
                copy_board[i] = tmp;
                min_row_changes = row_changes;
              }
            }
            total_changes += min_row_changes;
          }
          if (total_changes < min_total_changes) {
            min_total_changes = total_changes;
            ans = copy_board;
          }
        }
      }
    }
  }

  for (char c1 : letters) {
    for (char c2 : letters) {
      if (c2 <= c1) continue;
      for (char c3 : letters) {
        if (c1 == c3 || c2 == c3) continue;
        for (char c4 : letters) {
          if (c1 == c4 || c2 == c4 || c4 <= c3) continue;
          vector<vector<char>> cs = {{c1, c2}, {c3, c4}};
          int total_changes = 0;
          for (int i = 0; i < m; i++) {
            int min_row_changes = n + 1;
            for (int order = 0; order < 2; order++) {
              int row_changes = 0;
              string tmp(n, '.');
              for (int j = 0; j < n; j++) {
                tmp[j] = cs[i % 2][(j + order) % 2];
                if (tmp[j] != board[j][i]) {
                  row_changes++;
                }
              }
              if (row_changes < min_row_changes) {
                for (int k = 0; k < n; k++) copy_board[k][i] = tmp[k];
                min_row_changes = row_changes;
              }
            }
            total_changes += min_row_changes;
          }
          if (total_changes < min_total_changes) {
            min_total_changes = total_changes;
            ans = copy_board;
          }
        }
      }
    }
  }

  for (string s : ans) {
    cout << s << endl;
  }
}