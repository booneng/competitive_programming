#include <iostream>
#include <set>
#include <algorithm>

#define ll long long int
using namespace std;

int d[100005];
int a[100005];
int b[100005];
int counts[100005];
int s;

int go(int left, int right) {
  if (left > right) return 0;
  if (left == right) {
    counts[1]++;
    return 1;
  }
  int mid = (left + right) / 2;
  int max_left = go(left, mid - 1);
  int max_right = go(mid + 1, right);
  int ans = max(max_left, max_right);
  int m = d[mid] + a[mid];
  int n = d[mid] - b[mid];
  int mx[2], nx[2];
  
  for (int i = mid; i >= left; i--) {
    if (d[i] + a[i] != m) {
      nx[0] = d[i] - b[i];
      break;
    }
  }
  for (int i = mid; i <= right; i++) {
    if (d[i] + a[i] != m) {
      nx[1] = d[i] - b[i];
      break;
    }
  }
  for (int i = mid; i >= left; i--) {
    if (d[i] - b[i] != n) {
      mx[0] = d[i] + a[i];
      break;
    }
  }
  for (int i = mid; i <= right; i++) {
    if (d[i] - b[i] != n) {
      mx[1] = d[i] + a[i];
      break;
    }
  }
  
  set<pair<int, int> > seen;
  for (int i = 0; i < 2; i++) {
    int ni = nx[i];
    int cur = 1;
    int l = mid;
    int r = mid;
    for (int j = mid + 1; j <= right; j++) {
      if (d[j] + a[j] == m || d[j] - b[j] == ni) {
	cur++;
	r = j;
      }
      else {
	break;
      }
    }
    for (int j = mid - 1; j >= left; j--) {
      if (d[j] + a[j] == m || d[j] - b[j] == ni) {
	cur++;
	l = j;
      }
      else {
	break;
      }
    }
    ans = max(ans, cur);
    if (seen.find(make_pair(l, r)) == seen.end()) {
      seen.insert(make_pair(l, r));
      counts[cur]++;
    }
    l = mid;
    r = mid;
    cur = 1;
    int mi = mx[i];
    for (int j = mid + 1; j <= right; j++) {
      if (d[j] + a[j] == mi || d[j] - b[j] == n) {
	cur++;
	r = j;
      }
      else {
	break;
      }
    }
    for (int j = mid - 1; j >= left; j--) {
      if (d[j] + a[j] == mi || d[j] - b[j] == n) {
	cur++;
	l = j;
      }
      else {
	break;
      }
    }
    ans = max(ans, cur);
    if (seen.find(make_pair(l, r)) == seen.end()) {
      seen.insert(make_pair(l, r));
      counts[cur]++;
    }
  }
  return ans;
}


void solve() {
  cin >> s;
  for (int i = 0; i < s; i++) {
    cin >> d[i] >> a[i] >> b[i];
    counts[i] = 0;
  }
  counts[s] = 0;
  int max_length = go(0, s - 1);
  cout << max_length << ' ' << counts[max_length] << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }

}
