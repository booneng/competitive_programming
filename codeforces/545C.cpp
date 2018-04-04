#include <iostream>
#define ll long long int

using namespace std;

int main() {
  int n;
  cin >> n;
  ll x[n], h[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
  }
  int count = 1;
  bool fell_right = false;
  for (int i = 1; i < n - 1; i++) {
    if (!fell_right) {
      if (x[i] - h[i] > x[i - 1]) {
	count++;
      }
      else if (x[i] + h[i] < x[i + 1]) {
	count++;
	fell_right = true;
      }
    }
    else {
      if (x[i] - h[i] > x[i - 1] + h[i - 1]) {
	count++;
	fell_right = false;
      }
      else if (x[i] + h[i] < x[i + 1]) {
	count++;
      }
      else {
	fell_right = false;
      }
    }
  }
  if (n > 1) count++;
  cout << count;
}
