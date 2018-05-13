#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string board[305];
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    int a = 0;
    int b = i;
    char new_grid[305][305];
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
	new_grid[(j + a) % n][(k + b) % n] = board[j][k];
      }
    }

    bool ok = true;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
	if (new_grid[j][k] != new_grid[k][j]) {
	  ok = false;
	  break;
	}
      }
      if (!ok) break;
    }
    if (ok) count++;
  }
  
  cout << count * n;

}
