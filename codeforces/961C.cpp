#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  string pieces[4][n];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> pieces[i][j];
    }
  }

  int wrong_counts[4][2];
  for (int i = 0; i < 4; i++) {
    for (int m = 0; m < 2; m++) {
      int count = 0;
      for (int j = 0; j < n; j++) {
	for (int k = 0; k < n; k++) {
	  if ((j + k) % 2) {
	    if (m == 0 && pieces[i][j][k] == '1') count++;
	    else if (m == 1 && pieces[i][j][k] == '0') count++;
	  }
	  else {
	    if (m == 0 && pieces[i][j][k] == '0') count++;
	    else if (m == 1 && pieces[i][j][k] == '1') count++;
	  }
	}
      }
      wrong_counts[i][m] = count;
    }
  }

  int min_change = n * n * 4;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = 0; k < 3; k++) {
	if (k == i || k == j) continue;
	for (int l = k + 1; l < 4; l++) {
	  if (l == i || l == j) continue;
	  int change = wrong_counts[i][0] + wrong_counts[j][0] + wrong_counts[k][1] + wrong_counts[l][1];
	  if (change < min_change) min_change = change;
	}
      }
    }
  }
  cout << min_change;
  
}
