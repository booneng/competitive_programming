#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << 0;
    return 0;
  }
  vector<long long> a(n);
  long long sum = 0;
  long long max1 = 0, max2 = 0;
  unordered_map<long long, vector<int>> vals;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] >= max1) {
      max2 = max1;
      max1 = a[i];
    }
    else if (a[i] >= max2) {
      max2 = a[i];
    }
    vals[a[i]].push_back(i + 1);
  }
  if (max1 == max2) {
    long long cmp = sum - 2 * max1;
    cout << vals[cmp].size() << endl;
    for (int i : vals[cmp]) {
      cout << i << ' ';
    }
  }
  else {
    long long cmp1 = sum - 2 * max1;
    int size = cmp1 == max1 ? 0 : vals[cmp1].size();
    long long cmp2 = sum - 2 * max2;
    size += vals[cmp2].size();
    cout << size << endl;
    if (cmp1 != max1) {
      for (int i : vals[cmp1]) {
	cout << i << ' ';
      }
    }
    for (int i : vals[cmp2]) {
      cout << i << ' ';
    }
  }
}
