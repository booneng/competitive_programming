#include <iostream>

using namespace std;

int n, w;
int a[1005];

int main() {
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int max_add = 0;
  int min_minus = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    max_add = max(max_add, cur);
    min_minus = min(min_minus, cur);
  }

  int lower_bound = -min_minus;
  int upper_bound = w - max_add;
  if (upper_bound < lower_bound) {
    cout << 0;
  }
  else {
    cout << upper_bound - lower_bound + 1;
  }
  
}
