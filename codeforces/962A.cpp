#include <iostream>

#define ll long long int

using namespace std;

int main() {
  int n;
  cin >> n;
  ll total = 0;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    total += a[i];
  }
  ll threshold = (total % 2) ? total / 2 + 1 : total / 2;
  ll current = 0;
  for (int i = 1; i <= n; i++) {
    current += a[i];
    if (current >= threshold) {
      cout << i;
      break;
    }
  }
}
