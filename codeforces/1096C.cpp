#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int theta;
    cin >> theta;
    int i = 3;
    while (true) {
      int rhs = theta * i;
      if (rhs % 180 == 0) {
        int k = rhs / 180;
        if (k <= i - 2) {
          break;
        }
      }
      i++;
    }
    cout << i << endl;
  }

}