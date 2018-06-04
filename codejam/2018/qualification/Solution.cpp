#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a;
    cin >> a;
    int length = 3;
    int height = 3;
    if (height * 1000 < a) {
      length = 1000;
    }
    while (height * length < a) {
      height++;
    }

    int r = 0;
    int c = 0;
    int rf, cf;
    while (1) {
      cout << 2 + r << ' ' << 2 + c << endl;
      cout.flush();
      r = (r + 1) % (height - 2);
      c = (c + 1) % (length - 2);
      cin >> rf >> cf;
      if (rf == 0 && cf == 0) {
	break;
      }
      else if (rf == -1 && cf == -1) {
	return 0;
      }
    }
  }
}
