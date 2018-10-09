#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maximumK(vector<int>& arr, int k) {
  int n = arr.size();
  vector<int> ans;
  deque<int> topk;
  for (int i = 0; i < n; i++) {
    if (topk.size() == k) topk.pop_front();
    while (topk.size() > 0 && arr[i] > topk.back()) topk.pop_back();
    topk.push_back(arr[i]);
    if (i >= k - 1) cout << topk.front() << endl;
  }
  return ans;
}


int main() {
  int k, n;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  maximumK(arr, k);
}
