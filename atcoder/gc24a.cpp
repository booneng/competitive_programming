#include <iostream>

#define ll long long int

using namespace std;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2) {
    cout << b - a;
  }
  else {
    cout << a - b;
  }
}
