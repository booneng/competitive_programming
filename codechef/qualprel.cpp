#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
      cin >> scores[i];
    }
    sort(scores.rbegin(), scores.rend());
    int left = k;
    int right = n - 1;
    int target = scores[k - 1];
    while (left <= right) {
      int mid = (left + right) / 2;
      if (scores[mid] < target) {
	right = mid - 1;
      }
      else {
	left = mid + 1;
      }
    }
    cout << left << endl;
  }

}
