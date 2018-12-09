#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
  int n;
  vector<int> tree;
  vector<int> lo;
  vector<int> hi;
  vector<int> delta;


  void update(int i) {
    tree[i] = min(tree[2 * i + 1] + delta[2 * i + 1], tree[2 * i + 2] + delta[2 * i + 2]);
  }
  
  void prop(int i) {
    delta[2 * i + 1] += delta[i];
    delta[2 * i + 2] += delta[i];
    delta[i] = 0;
  }
  
  void increment(int i, int left, int right, int val) {
    if (left > hi[i] || right < lo[i]) return;

    if (left <= lo[i] && hi[i] <= right) {
      delta[i] += val;
      return;
    }

    prop(i);
    increment(2 * i + 1, left, right, val);
    increment(2 * i + 2, left, right, val);
    update(i);
  }

  int minimum(int i, int left, int right) {
    if (left > hi[i] || right < lo[i]) return INT_MAX;

    if (left <= lo[i] && hi[i] <= right) {
      return tree[i] + delta[i];
    }

    prop(i);

    int minLeft = minimum(2 * i + 1, left, right);
    int minRight = minimum(2 * i + 2, left, right);
    
    update(i);
    // not return tree[i] because right/left min might return INT_MAX
    // this is partial overlap
    return min(minLeft, minRight);
  }
public:

  SegmentTree(const vector<int>& nums) : n(nums.size()) {
    tree = vector<int>(4 * n);
    lo = vector<int>(4 * n);
    hi = vector<int>(4 * n);
    delta = vector<int>(4 * n);
    init(nums, 0, 0, n - 1);
  }


  void init(const vector<int>& nums, int i, int left, int right) {
    lo[i] = left;
    hi[i] = right;
    if (left == right) {
      tree[i] = nums[left];
      return;
    }

    int mid = (left + right) / 2;
    init(nums, 2 * i + 1, left, mid);
    init(nums, 2 * i + 2, mid + 1, right);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
  }

  
  void increment(int left, int right, int val) {
    increment(0, left, right, val);
  }

  int minimum(int left, int right) {
    return minimum(0, left, right);
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  SegmentTree st(a);

  int m;
  cin >> m;
  cin.ignore(256, '\n');
  for (int i = 0; i < m; i++) {
    vector<int> tmp;
    while (cin.peek() != '\n') {
      int num;
      cin >> num;
      tmp.push_back(num);
    }
    cin.ignore(256, '\n');
    int lf = tmp[0];
    int rf = tmp[1];
    if (tmp.size() == 2) {
      if (lf > rf) {
	int m1 = st.minimum(lf, n - 1);
	int m2 = st.minimum(0, rf);
	cout << min(m1, m2) << endl;
      }
      else {
	cout << st.minimum(lf, rf) << endl;
      }
    }
    else {
      int v = tmp[2];
      if (lf > rf) {
	st.increment(lf, n - 1, v);
	st.increment(0, rf, v);
      }
      else {
	st.increment(lf, rf, v);
      }
    }
  }

}
