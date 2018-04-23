#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  int ans = 1 + n / 2;
  cout << ans;
}
