#include <iostream>
#include <vector>

using namespace std;

void min_missing(vector<int> arr) {
  int n = arr.size();
  int end = n - 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= 0 && i < end) {
      int temp = arr[i];
      arr[i] = arr[end];
      arr[end] = temp;
      i--;
      end--;
    }
  }
  vector<bool> positive(end + 1, false);
  for (int i = 0; i < end + 1; i++) {
    if (arr[i] > 0 && arr[i] <= end + 1) {
      positive[arr[i] - 1] = true;
    }
  }

  for (int i = 0; i < end + 1; i++) {
    if (!positive[i]) {
      cout << i + 1;
      return;
    }
  }
  cout << end + 2;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  min_missing(arr);
}
