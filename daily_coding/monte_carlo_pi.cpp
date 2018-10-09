#include <iostream>

using namespace std;

int main() {
  int n = 10000000;
  int in_circle = 0;
  for (int i = 1; i <= n; i++) {
    double x = (double)rand() * 2 / RAND_MAX - 1;
    double y = (double)rand() * 2 / RAND_MAX - 1;
    if (x * x + y * y <= 1) {
      in_circle++;
    }
    cout << 4 * (double)in_circle / i << endl;
  }
}
