#include <bits/stdc++.h>

using namespace std;
// also see 52C for lazy propagation segment tree
class SegmentTree {
private:
    int n;
    vector<int> segmentTree;

    void updateTree(int value, int index, int left, int right, int pos) {
        if (index < left || index > right) return;

        if (left == right) {
            segmentTree[pos] = value;
            return;
        }

        int mid = (left + right) / 2;
        updateTree(value, index, left, mid, 2 * pos + 1);
        updateTree(value, index, mid + 1, right, 2 * pos + 2);
        segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

    int maxQuery(int start, int end, int left, int right, int pos) {
        if (start <= left && end >= right) {
            return segmentTree[pos];
        }

        if (start > right || end < left) {
            return numeric_limits<int>::min();
        }

        int mid = (left + right) / 2;
        return max(maxQuery(start, end, left, mid, 2 * pos + 1),
                 maxQuery(start, end, mid + 1, right, 2 * pos + 2));
    }
    
public:

    SegmentTree(int n) : n(n) {
        segmentTree = vector<int>(4 * n, numeric_limits<int>::min());
    }

    void updateTree(int value, int index) {
        updateTree(value, index, 0, n - 1, 0);
    }

    int maxQuery(int start, int end) {
        return maxQuery(start, end, 0, n - 1, 0);
    }

    
}

int main() {

}