#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vector<int> ans(n);
  vector<int> r(n);
  ans[0] = 1;
  for (int i = 1; i < n; i++) {
    ans[i] = ans[i - 1] * nums[i - 1];
  }
  int temp = 1;
  for (int i = n - 2; i >= 0; i--) {
    temp *= nums[i + 1];
    ans[i] *= temp;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
