#include <bits/stdc++.h>

using namespace std;

void updateTree(long long value, int index, int left, int right, int pos, vector<long long>& segmentTree) {
  if (index < left || index > right) {
    return;
  }
  if (left == right) {
    segmentTree[pos] = value;
    return;
  }

  int mid = (left + right) / 2;
  
  updateTree(value, index, left, mid, 2 * pos + 1, segmentTree);
  updateTree(value, index, mid + 1, right, 2 * pos + 2, segmentTree);
  segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

long long maxQuery(int start, int end, int left, int right, int pos, const vector<long long>& segmentTree) {
  if (start <= left && end >= right) {
    return segmentTree[pos];
  }

  if (start > right  || end < left) {
    return numeric_limits<long long>::min();
  }

  int mid = (left + right) / 2;

  return max(maxQuery(start, end, left, mid, 2 * pos + 1, segmentTree),
	     maxQuery(start, end, mid + 1, right, 2 * pos + 2, segmentTree));
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (x < n / k) {
    cout << -1;
    return 0;
  }

  vector<long long> segmentTree(4 * n, numeric_limits<long long>::min());
  
  for (int i = 0; i < k; i++) {
    updateTree(a[i], i, 0, n - 1, 0, segmentTree);
  }
  
  for (int j = 1; j < x; j++) {
    vector<long long> updates(n, numeric_limits<long long>::min());
    for (int i = j; i < n; i++) {
      long long maxP = maxQuery(max(i - k, 0), i - 1, 0, n - 1, 0, segmentTree);
      if (maxP >= 0) {
	      updates[i] = maxP + a[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (updates[i] >= 0) updateTree(updates[i], i, 0, n - 1, 0, segmentTree);
    }
  }

  long long ans = -1;
  ans = max(ans, maxQuery(n - k, n - 1, 0, n - 1, 0, segmentTree));

  cout << ans;
}
