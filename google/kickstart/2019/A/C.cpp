#include <bits/stdc++.h>

using namespace std;

const int Q = 30005;

int ones[Q];

class SegmentTree {
	int n;
	vector<unordered_set<int>> tree;
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

    void increment(int i, int left, int right, int val, int idx) {
        if (left > hi[i] || right < lo[i]) return;

        if (left <= lo[i] && right >= hi[i]) {
            if (val == 1) tree[i].insert(idx);
            else tree[i].erase(idx);
            delta[i] += val;
            return;
        }

        prop(i);
        increment(2 * i + 1, left, right, val, idx);
        increment(2 * i + 2, left, right, val, idx);
    }

    int CountOnes(int i, int left, int right, set<int> covers) {
        if (left > hi[i] || right < lo[i]) return 0;

        if (delta[i] > 1) return 0;

        if (left <= lo[i] && right >= hi[i]) {
            for (int c : tree[i]) {
                covers.insert(c);
            }
        }

        if (lo[i] == hi[i]) {
            if (delta[i] == 1) {
                for (int c : covers) {
                    ones[c]++;
                }
                return 1;
            }
            return 0;
        }

        prop(i);
        int cnt = 0;
        cnt += CountOnes(2 * i + 1, left, right, covers);
        cnt += CountOnes(2 * i + 2, left, right, covers);
        return cnt;
    }

public:
	
    SegmentTree(int n) {
        this->n = n;
        tree = vector<unordered_set<int>>(4 * n);
        lo = vector<int>(4 * n);
        hi = vector<int>(4 * n);
        delta = vector<int>(4 * n);

        init(0, 1, n);
    }

    void increment(int left, int right, int val, int idx) {
        increment(0, left, right, val, idx);
    }

    int CountOnes(int left, int right) {
        set<int> covers;
        return CountOnes(0, left, right, covers);
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
        st.increment(l[i], r[i], 1, i);
        ones[i] = 0;
    }

    st.CountOnes(1, n);

    vector<bool> used(q, false);
    int ans = n;
    for (int i = 0; i < q; i++) {
        int idx = 0;
        int m = -1;
        for (int j = 0; j < q; j++) {
            if (used[j]) continue;
            // int cur = st.CountOnes(l[j], r[j]);
            int cur = ones[j];
            if (cur > m) {
                m = cur;
                idx = j;
            }
        }
        used[idx] = true;
        ans = min(ans, m);
        st.increment(l[idx], r[idx], -1, idx);
        st.CountOnes(l[idx], r[idx]);
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
