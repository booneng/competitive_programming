#include <iostream>
#include <vector>
#include <string>

using namespace std;

void move(vector<vector<int> >& a, vector<string>& moves, int i, int j, int h, int w) {
  a[i][j]--;
  if (i < h - 1) {
    a[i + 1][j]++;
    moves.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 2) + " " + to_string(j + 1));
  }
  else if (j < w - 1) {
    a[i][j + 1]++;
    moves.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 1) + " " + to_string(j + 2));
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int> > a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<string> moves;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] % 2) {
	move(a, moves, i, j, h, w);
      }
    }
  }
  cout << moves.size() << endl;
  for (string s : moves) {
    cout << s << endl;
  }
}
