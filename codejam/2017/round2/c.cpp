#include <iostream>
#include <vector>
#include <string>

using namespace std;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
string grid[55];
bool fail[55][55][2];
int beam_paths[55][55][2][55][55];
int r, c;
int x[5000], y[5000];
int rotations[55];

void go(int i, int j, int rot, int ii, int jj, int dir) {
  beam_paths[i][j][rot][ii][jj] = 1;
  ii += dx[dir];
  jj += dy[dir];
  if (ii < 0 || jj < 0 || ii >= r || jj >= c) return;
  if (grid[ii][jj] == '#') return;
  if (grid[ii][jj] == '-' || grid[ii][jj] == '|') {
    fail[i][j][rot] = true;
    return;
  }
  if (grid[ii][jj] == '\\') {
    if (dir == 0) dir = 1; else
    if (dir == 1) dir = 0; else
    if (dir == 2) dir = 3; else
    if (dir == 3) dir = 2;
  }
  if (grid[ii][jj] == '/') {
    if (dir == 0) dir = 3; else
    if (dir == 1) dir = 2; else
    if (dir == 2) dir = 1; else
    if (dir == 3) dir = 0;
  }
  go(i, j, rot, ii, jj, dir);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      cin >> grid[i];
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
	for (int rot = 0; rot < 2; rot++) {  
	  for (int k = 0; k < r; k++) {
	    for (int l = 0; l < c; l++) {
	      beam_paths[i][j][rot][k][l] = 0;
	    }
	  }
	}
      }
    }
    
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
	for (int rot = 0; rot < 2; rot++) {
	  fail[i][j][rot] = false;
	  if (!(grid[i][j] == '|' || grid[i][j] == '-')) continue;
	  go(i, j, rot, i, j, 0 + rot);
	  go(i, j, rot, i, j, 2 + rot);
	}
      }
    }

    int count = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
	if (grid[i][j] == '-' || grid[i][j] == '|') {
	  x[count] = i;
	  y[count] = j;
	  rotations[count] = -1;
	  count++;
	}
      }
    }
    bool err = false;
    for (int i = 0; i < count; i++) {
      for (int rot = 0; rot < 2; rot++) {
	if (fail[x[i]][y[i]][rot]) {
	  if (fail[x[i]][y[i]][rot ^ 1]) {
	    err = true;
	    break;
	  }
	  rotations[i] = rot ^ 1;
	}
      }
    }
    bool done = false;
    while (!done) {
      done = true;
      for (int ii = 0; ii < r; ii++) {
	for (int jj = 0; jj < c; jj++) {
	  if (grid[ii][jj] != '.') continue;
	  int found_count = 0;
	  int bc, br;
	  for (int i = 0; i < count; i++) {
	    for (int rot = 0; rot < 2; rot++) {
	      if (beam_paths[x[i]][y[i]][rot][ii][jj]) {
		if (rotations[i] != (rot ^ 1)) {
		  found_count++;
		  // rotations[i] = rot;
		  bc = i;
		  br = rot;
		}
	      }
	    }
	  }
	  if (found_count == 0) {
	    err = true;
	  }
	  else if (found_count == 1) {
	    if (rotations[bc] != br) done = false;
	    rotations[bc] = br;
	  }
	}
      }
    }
    
    // build implication graph
    vector<pair<int, int> > adj[55][2];
    set<int> nodes;
    for (int ii = 0; ii < r; ii++) {
      for (int jj = 0; jj < c; jj++) {
	if (grid[ii][jj] != '.') continue;
	int found_count = 0;
	int bc, br;
	vector<pair<int, int> > cross_paths;
	for (int i = 0; i < count; i++) {
	  for (int rot = 0; rot < 2; rot++) {
	    if (beam_paths[x[i]][y[i]][rot][ii][jj]) {
	      if (rotations[i] < 0) {
		found_count++;
		cross_paths.push_back(make_pair(i, rot));
	      }
	    }
	  }
	}
	if (found_count == 2) {
	  set<int> nodes;
	  nodes.insert(cross_paths[0].first);
	  nodes.insert(cross_paths[1].first);
	  pair<int, int> one = cross_paths[0];
	  pair<int, int> two = cross_paths[1];
	  adj[one.first][one.second ^ 1].push_back(make_pair(two.first, two.second));	  adj[two.first][two.second ^ 1].push_back(make_pair(one.first, one.second));
	}
      }
    }

    bool visited[55][2];
    for (int i = 0; i < count; i++) {
      for (int rot = 0; rot < count; rot++) {
	visited[i][rot] = false;
      }
    }
    
    if (err) {
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    }
    else {
      cout << "Case #" << t << ": " << "POSSIBLE" << endl;
      for (int i = 0; i < count; i++) {
	if (rotations[i] >= 0) {
	  grid[x[i]][y[i]] = (rotations[i] == 0) ? '|' : '-';
	}
	else {
	  grid[x[i]][y[i]] = '-';
	}
      }
      for (int i = 0; i < r; i++) {
	cout << grid[i] << endl;
      }
    }
  }

}
