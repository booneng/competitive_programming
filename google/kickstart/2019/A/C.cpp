#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
	int n;
	vector<int> tree;
	vector<int> lo;
	vector<int> hi;
	vector<int> delta;


    void init(int i, int left, int right) {
        lo[i] = left;
        hi[i] = right;

        if (left == right) return;

        int mid = (left + right) / 2;
        init(2 * i + 1, left, mid);
        init(2 * i + 2, mid + 1, right);
    }

    void prop(int i) {
        delta[2 * i + 1] += delta[i];
        delta[2 * i + 2] += delta[i];
        delta[i] = 0;
    }

    void update(int i) {
        tree[i] = tree[2 * i + 1] + delta[2 * i + 1] + tree[2 * i + 2] + delta[2 * i + 2];
    }

    void increment(int i, int left, int right, int val) {
        if (left > hi[i] || right < lo[i]) return;

        if (left <= lo[i] && right >= hi[i]) {
            delta[i] += val;
            return;
        }

        prop(i);
        increment(2 * i + 1, left, right, val);
        increment(2 * i + 2, left, right, val);
        update(i);
    }

    int CountOnes(int i, int left, int right) {
        if (left > hi[i] || right < lo[i]) return 0;

        if (delta[i] > 1) return 0;

        if (left <= lo[i] && right >= hi[i] && tree[i] + delta[i] == hi[i] - lo[i] + 1) {
            return hi[i] - lo[i] + 1;
        }

        if (lo[i] == hi[i]) return 0;

        prop(i);
        int cnt = 0;
        cnt += CountOnes(2 * i + 1, left, right);
        cnt += CountOnes(2 * i + 2, left, right);
        update(i);
        return cnt;
    }

public:
	
    SegmentTree(int n) {
        this->n = n;
        tree = vector<int>(4 * n);
        lo = vector<int>(4 * n);
        hi = vector<int>(4 * n);
        delta = vector<int>(4 * n);

        init(0, 1, n);
    }

    void increment(int left, int right, int val) {
        increment(0, left, right, val);
    }

    int CountOnes(int left, int right) {
        return CountOnes(0, left, right);
    }

};

int solve() {
	int n, q;
	cin >> n >> q;
	SegmentTree st(n);
    vector<int> l(q);
    vector<int> r(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        st.increment(l[i], r[i], 1);
    }

    vector<bool> used(q, false);
    int ans = n;
    for (int i = 0; i < q; i++) {
        int idx = 0;
        int m = -1;
        for (int j = 0; j < q; j++) {
            if (used[j]) continue;
            int cur = st.CountOnes(l[j], r[j]);
            if (cur > m) {
                m = cur;
                idx = j;
            }
        }
        used[idx] = true;
        ans = min(ans, m);
        st.increment(l[idx], r[idx], -1);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}
