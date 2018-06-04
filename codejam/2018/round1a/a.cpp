#include <iostream>
#include <string>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int rows[105] = {0};
    int cols[105] = {0};
    int hslices[105];
    int vslices[105];
    int r, c, h, v;
    cin >> r >> c >> h >> v;
    string waffle[r];
    for (int j = 0; j < r; j++) {
      cin >> waffle[j];
    }
    int chips = 0;
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
	if (waffle[j][k] == '@') {
	  rows[j]++;
	  cols[k]++;
	  chips++;
	}
      }
    }
    cout << "Case #" << i << ": ";
    if (chips % (h + 1) || chips % (v + 1) || chips % ((h + 1) * (v + 1))) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    int sum = 0;
    int point = chips / (h + 1);
    int slice_count = 0;
    bool done = false;
    for (int j = 0; j < r; j++) {
      sum += rows[j];
      if (sum == point) {
	hslices[slice_count] = j;
	slice_count++;
	sum = 0;
      }
      else if (sum > point) {
	cout << "IMPOSSIBLE" << endl;
	done = true;
	break;
      }
    }
    if (done) continue;
    if (sum > 0 || slice_count < h - 1) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    point = chips / (v + 1);
    slice_count = 0;
    for (int j = 0; j < c; j++) {
      sum += cols[j];
      if (sum == point) {
	vslices[slice_count] = j;
	slice_count++;
	sum = 0;
      }
      else if (sum > point) {
	cout << "IMPOSSIBLE" << endl;
	done = true;
	break;
      }
    }
    if (done) continue;
    if (sum > 0 || slice_count < v - 1) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    int sums[105][105];
    if (waffle[0][0] == '@') sums[0][0] = 1;
    else sums[0][0] = 0;
    for (int j = 1; j < r; j++) {
      sums[j][0] = sums[j - 1][0];
      if (waffle[j][0] == '@') sums[j][0]++;
    }
    for (int j = 1; j < c; j++) {
      sums[0][j] = sums[0][j - 1];
      if (waffle[0][j] == '@') sums[0][j]++;
    }
    for (int j = 1; j < r; j++) {
      for (int k = 1; k < c; k++) {
	sums[j][k] = sums[j][k - 1] + sums[j - 1][k] - sums[j - 1][k - 1];
	if (waffle[j][k] == '@') sums[j][k]++;
      }
    }

    int split = chips / ((h + 1) * (v + 1));
    int prev = sums[hslices[0]][vslices[0]];
    if (prev != split) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    for (int j = 1; j < h; j++) {
      int cc = sums[hslices[j]][vslices[0]];
      cc -= sums[hslices[j - 1]][vslices[0]];
      if (cc != split) {
	cout << "IMPOSSIBLE" << endl;
	done = true;
	break;
      }
    }
    if (done) continue;
    prev = sums[hslices[0]][vslices[0]];
    for (int j = 1; j < v; j++) {
      int cc = sums[hslices[0]][vslices[j]];
      cc -= sums[hslices[0]][vslices[j - 1]];
      if (cc != split) {
	cout << "IMPOSSIBLE" << endl;
	done = true;
	break;
      }
    }
    if (done) continue;
    for (int j = 1; j < h; j++) {
      for (int k = 1; k < v; k++) {
	int cc = sums[hslices[j]][vslices[k]];
	cc -= sums[hslices[j]][vslices[k - 1]];
	cc -= sums[hslices[j - 1]][vslices[k]];
	cc += sums[hslices[j - 1]][vslices[k - 1]];
	if (cc != split) {
	  cout << "IMPOSSIBLE" << endl;
	  done = true;
	  break;
	}
      }
    }
    if (done) continue;
    cout << "POSSIBLE" << endl;
  }
}
