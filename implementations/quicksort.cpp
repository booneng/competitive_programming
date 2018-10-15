#include <iostream>
#include <vector>

using namespace std;

void quicksortHelper(vector<int>& arr, int left, int right) {
  int pivot = arr[(left + right) / 2];
  int l = left;
  int r = right;
  while (left <= right) {
    while (arr[left] < pivot) left++;
    while (arr[right] > pivot) right--;

    if (left <= right) {
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  int index = left;
  if (l < index - 1) {
    quicksortHelper(arr, l, index - 1);
  }
  if (r > index) {
    quicksortHelper(arr, index, r);
  }
}

void quicksort(vector<int>& arr) {
  quicksortHelper(arr, 0, arr.size() - 1);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  quicksort(arr);
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}
