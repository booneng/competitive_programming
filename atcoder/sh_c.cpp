#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double n, m, d;
  
  cin >> n >> m >> d;
  cout << setprecision(10);
  double ans;
  if (d == 0) ans = 1.0 / n;
  else ans = (2 * (n - d)) / (n * n);
  ans *= m - 1;
  cout << ans;
}
