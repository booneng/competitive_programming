#include <iostream>

#define ll long long int

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n <= 5) {
    cout << -1 << endl;
  }
  else {
    for (int i = 0; i < n / 2; i++) {
      cout << 1 << ' ' << i + 2 << endl;
    }
    for (int i = 0; i < n / 2 - 1; i++) {
      cout << 2 << ' ' << i + n / 2 + 2 << endl; 
    }
    if (n % 2) {
      cout << 2 << ' ' << n << endl;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << 1 << ' ' << i + 2 << endl;
  }
}
