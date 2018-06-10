#include <iostream>

using namespace std;

int main() {
  int n, d1, d2;
  cin >> n >> d1 >> d2;
  int n1 = 0, n2 = 0;
  while (d1 % (1 << (n1 + 1)) == 0) n1++;
  while (d2 % (1 << (n2 + 1)) == 0) n2++;
  int c = 0;
  for (int i = 0; i < 2 * n && c < n * n; i++) {
    for (int j = 0; j < 2 * n && c < n * n; j++) {
      if ((n1 % 2 == 0 ? (1 >> (n1 / 2)) % 2 == (j >> (n1 / 2)) % 2 : (i >> (n1 / 2)) % 2 == 0) && (n2 % 2 == 0 ? (j >> (n2 / 2)) % 2 == (j >> (n2 / 2)) % 2 : (i >> (n2 / 2)) % 2 == 0)) {
	cout << i << ' ' << j << endl;
	c++;
      }
    }
  }
  return 0;
}

