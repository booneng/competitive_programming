#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int tmp;
  for (int i = 0; i < n; i++) cin >> tmp;
  if ((n - 1) % (k - 1)) {
    cout << (n - 1) / (k - 1) + 1;
  }
  else {
    cout << (n - 1) / (k - 1);
  }
}
