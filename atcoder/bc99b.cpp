#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int diff = b - a;
  int k = (diff - 1) * diff / 2;
  cout << k - a;

}
