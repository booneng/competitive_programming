#include <iostream>

#define ll long long int
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    int b;
    ll m;
    cin >> b >> m;
    if (m > (1LL << (b - 2))) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    cout << "POSSIBLE" << endl;
    for (int j = 0; j < b; j++) {
      for (int k = 0; k < b; k++) {
	if (k <= j) cout << '0';
	else if (k == b - 1) {
	  if (j == 0 || ((m - 1) & (1LL << (j - 1)))) cout << '1';
	  else cout << '0';
	}
	else {
	  cout << '1';
	}
      }
      cout << endl;
    }
  }

}
