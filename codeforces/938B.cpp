#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mid = 500000;
  int max_left = 0;
  int max_right = 1000000;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p <= mid && p > max_left) {
      max_left = p;
    }
    else if (p > mid && p < max_right) {
      max_right = p;
    }
  }
  int max = (max_left - 1 > 1000000 - max_right) ? max_left - 1 : 1000000 - max_right;
  cout << max;
}
