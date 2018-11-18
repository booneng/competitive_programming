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
  map<long long, vector<int>> vals;
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

  long long r1 = sum - 2 * max1;
  vector<int> ans;
  if (r1 != max1 || vals[r1].size() > 1) {
    ans = vals[r1];
  }
  if (max2 != max1) {
    long long r2 = sum - 2 * max2;
    if (r2 == max1) {
      for (int i : vals[r2]) ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << ' ';
}
