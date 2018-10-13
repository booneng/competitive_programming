#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int left = 0;
  int right = n;

  while (left <= right) {
    int mid = (left + right) / 2;
    bool can = true;
    int current_box = 0;
    int current_size = k;
    for (int i = n - mid; i < n; i++) {
      if (a[i] <= current_size) {
	current_size -= a[i];
      }
      else {
	current_box++;
	current_size = k;
	i--;
	if (current_box == m) {
	  can = false;
	  break;
	}
      }
    }
    if (can) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }

  cout << right;
}
