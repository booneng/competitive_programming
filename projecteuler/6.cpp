#include <iostream>

#define ll long long int

using namespace std;

int main() {
  ll n1 = 0;
  ll n2 = 0;
  for (ll i = 1; i <= 100; i++) {
    n1 += i * i;
    n2 += i;
  }
  n2 = n2 * n2;
  cout << n2 - n1;
}
