#include <iostream>
#include <vector>

#define ll long long int
using namespace std;

int main() {
  int n;
  cin >> n;
  ll m[n];
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    a[i] = max(a[i - 1], m[i] + 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    a[i] = max(a[i], a[i + 1] - 1);
  }
  ll d = 0;
  for (int i = 0; i < n; i++) {
    d += a[i] - m[i] - 1;
  }
  cout << d;
}
