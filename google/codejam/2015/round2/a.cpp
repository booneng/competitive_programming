#include <iostream>
#include <vector>
#include <string>

using namespace std;


string grid[105];
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

int r, c;
// 0: ^
// 1: <
// 2: v
// 3: >

void solve(int t) {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> grid[i];
  }

  bool fail = false;
  int count = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '.') continue;
      bool ok = false;
      int x = i, y = j;
      int dir = -1;
      if (grid[i][j] == '^') dir = 0;
      if (grid[i][j] == '<') dir = 1;
      if (grid[i][j] == 'v') dir = 2;
      if (grid[i][j] == '>') dir = 3;
      x += dir_x[dir];
      y += dir_y[dir];
      while (x >= 0 && x < r && y >= 0 && y < c) {
	if (grid[x][y] != '.') {
	  ok = true;
	  break;
	}
	x += dir_x[dir];
	y += dir_y[dir];
      }
      if (!ok) {
	for (int dir = 0; dir < 4; dir++) {
	  int x = i, y = j;
	  x += dir_x[dir];
	  y += dir_y[dir];
	  while (0 <= x && x < r && 0 <= y && y < c) {
	    if (grid[x][y] != '.') {
	      ok = true;
	      break;
	    }
	    x += dir_x[dir];
	    y += dir_y[dir];
	  }
	  if (ok) break;
	}
	if (!ok) {
	  fail = true;
	  break;
	}
	count++;
      }
    }
  }
  if (fail) cout << "Case #" << t << ": IMPOSSIBLE" << endl;
  else cout << "Case #" << t << ": " << count << endl;
  
}



int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
