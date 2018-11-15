#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2;
    return 0;
  }
  int end = sqrt(n);
  long long smallest_prime = 0;
  for (int i = 2; i <= end; i++) {
    if (n % i == 0) {
      cout << ((n - i) / 2 + 1);
      return 0;
    }
  }
  cout << 1;
}
