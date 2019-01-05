#include <bits/stdc++.h>

using namespace std;

string letters = "AGTC";

vector<string> get_permutations(int n) {
  if (n == 0) {
    string s;
    vector<string> res;
    res.push_back(s);
    return res;
  }
  vector<string> prev = get_permutations(n - 1);
  vector<string> res;
  for (string s : prev) {
    for (char c : letters) {
      bool can = true;
      for (char sc : s) {
        if (sc == c) {
          can = false;
          break;
        }
      }
      if (can) {
        string tmp = c + s;
        res.push_back(tmp);
      }
    }
  }
  return res;
}


int main() {
  int n, m;
  cin >> n >> m;

  vector<string> board(n);
  for (int i = 0; i < n; i++) cin >> board[i];
  vector<string> perms = get_permutations(4);
  vector<string> copy_board = board;
  vector<string> ans;
  int min_changes = n * m;
  for (string perm : perms) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int index = (2 * (i % 2) + j) % 4;
        copy_board[i][j] = perm[index];
      }
    }
    int changes = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (copy_board[i][j] != board[i][j]) changes++;
      }
    }
    if (changes < min_changes) {
      ans = copy_board;
      min_changes = changes;
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  
}