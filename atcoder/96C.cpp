#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int price = x * a + b * y;
  if (x > y) {
    int price1 = 0;
    if (2 * c < a + b) {
      price1 += c * 2 * y;
    }
    else {
      price1 += a * y + b * y;
    }
    if (2 * c < a) {
      price1 += 2 * c * (x - y);
    }
    else {
      price1 += a * (x - y);
    }
    price = min(price, price1);
  }
  if (x < y) {
    int price1 = 0;
    if (2 * c < a + b) {
      price1 += c * 2 * x;
    }
    else {
      price1 += a * x + b * x;
    }
    if (2 * c < b) {
      price1 += 2 * c * (y - x);
    }
    else {
      price1 += b * (y - x);
    }
    price = min(price, price1);
  }
  if (x == y && 2 * c < a + b) {
    price = 2 * c * x;
  }
  cout << price;
}
