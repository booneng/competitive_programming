#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int q[n + 1];
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    q[p] = i;
  }

  int max_length = 1;
  int cur_length = 1;
  for (int i = 1; i < n; i++) {
    if (q[i] < q[i + 1]) {
      cur_length++;
    }
    else {
      max_length = max(max_length, cur_length);
      cur_length = 1;
    }
  }
  max_length = max(max_length, cur_length);
  cout << n - max_length;
}
