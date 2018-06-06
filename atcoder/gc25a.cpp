#include <iostream>
#include <algorithm>

using namespace std;

int sum_digits(int a, int b) {
  int sum = 0;
  while (a) {
    sum += a % 10;
    a /= 10;
  }

  while (b) {
    sum += b % 10;
    b /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  int min_sum = 10005;
  for (int i = 1; i < n / 2 + 1; i++) {
    int a = i;
    int b = n - i;
    int sum_dig = sum_digits(a, b);
    min_sum = min(sum_dig, min_sum);
  }
  cout << min_sum;
}
