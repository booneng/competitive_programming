#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int j, p, s, k;
    cin >> j >> p >> s >> k;
    int per_j_p = min(s, k);
    int days = j * p * per_j_p;
    cout << "Case #" << i << ": " << days << endl;
    for (int i1 = 1; i1 <= j; i1++) {
      for (int i2 = 1; i2 <= p; i2++) {
	for (int i3 = i2 + i1 - 2; i3 < i2 + i1 - 2 + per_j_p; i3++) {
	  cout << i1 << ' ' << i2 << ' ' << (i3 % s) + 1 << endl;
	}
      }
    }
  }

}
