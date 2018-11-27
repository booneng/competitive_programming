#include <bits/stdc++.h>

using namespace std;

int extendedEuclidean(int x, int y, int& alpha, int &beta) {
  if (y == 0) {
    alpha = 1;
    beta = 0;
    return x;
  }

  int d = extendedEuclidean(y, x % y, alpha, beta);
  int tmp = alpha;
  alpha = beta;
  beta = tmp - (x / y) * beta;
  return d;
}

int main() {
  int alpha, beta;
  int mod = 1000000007;
  for (int i = 1; i < 10000; i++) {
    extendedEuclidean(mod, i, alpha, beta);
    cout << i << ' ' << beta << endl;
  }
}
