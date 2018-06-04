#include <iostream>
#include <algorithm>

using namespace std;

int c;
int b[105];
int has[105];
int ramps[105];
int reverse_ramps[105];

void solve() {
  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> b[i];
    has[i] = 1;
    ramps[i] = 0;
  }
  if (b[0] == 0 || b[c - 1] == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  int max_ramps = 0;
  for (int i = 0; i < c; i++) {
    if (has[i] == b[i]) continue;
    int diff = b[i] - has[i];
    if (diff > 0) {
      int last = 0;
      for (int j = i + 1; j < c; j++) {
        if (ramps[j] > 0) {
	  ramps[j] += diff;
	}
	else {
	  last = j;
	  break;
	}
      }
      for (int j = diff; j > 0; j--) {
	has[last]--;
	ramps[last] += j;
	last++;
      }
    }
    else {
      ramps[i] += diff;
      has[i + 1] += -diff;
    }
  }
  
  for (int i = 0; i < c; i++) {
    int tmp = max(ramps[i], -ramps[i]);
    max_ramps = max(tmp, max_ramps);
  }
  cout << max_ramps + 1 << endl;
  string rows[105];
  for (int i = 0; i < max_ramps; i++) {
    for (int j = 0; j < c; j++) {
      if (ramps[j] > 0 && ramps[j] > i) {
	rows[i] += '/';
      }
      else if (ramps[j] < 0 && -ramps[j] > i) {
	rows[i] += '\\';
      }
      else {
	rows[i] += '.';
      }
    }
  }
  for (int i = 0; i < c; i++) {
    rows[max_ramps] += '.';
  }
  for (int i = 0; i <= max_ramps; i++) {
    cout << rows[i] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
