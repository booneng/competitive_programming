#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int N = 300005;
const int K = 300000;

int parents[2 * K];
int sx[2 * K];
int sy[2 * K];
long long ans = 0;

int* where[80 * N];
int val[80 * N];
int cur = 0;

long long res[N];

vector<pair<int, int>> tree[4 * N];

void change(int& x, int y) {
    where[cur] = &x;
    val[cur] = x;
    x = y;
    cur++;
}

void rollback() {
    cur--;
    (*where[cur]) = val[cur];
}

int find(int x) {
    if (parents[x] == x) return x;
    return find(parents[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    ans -= sx[px] * 1LL * sy[px];
    ans -= sx[py] * 1LL * sy[py];
    if (sx[px] + sy[px] < sx[py] + sy[py]) {
        swap(px, py);
    }

    change(parents[py], px);
    change(sx[px], sx[px] + sx[py]);
    change(sy[px], sy[px] + sy[py]);
    ans += sx[px] * 1LL * sy[px];
}

void dfs(int idx, int left, int right) {
    int state = cur;
    long long last_ans = ans;

    for (auto point : tree[idx]) {
        merge(point.first, point.second + K);
    }
    if (left == right - 1) {
        res[left] = ans;
    }
    else {
        int mid = (left + right) / 2;
        dfs(idx * 2 + 1, left, mid);
        dfs(idx * 2 + 2, mid, right);
    }

    while (cur != state) rollback();
    ans = last_ans;
}

void init() {
    for (int i = 0; i < K; i++) {
        parents[i] = i;
        parents[i + K] = i + K;
        sx[i] = 1;
        sy[i + K] = 1;
    }
}

void add(int idx, int lo, int hi, int left, int right, pair<int, int> val) {
    if (left >= right) return;

    if (left == lo && right == hi) {
        tree[idx].push_back(val);
    }
    else {
        int mid = (lo + hi) / 2;
        add(2 * idx + 1, lo, mid, left, min(mid, right), val);
        add(2 * idx + 2, mid, hi, max(mid, left), right, val);
    }
}

int main() {
    int q;
    cin >> q;
    map<pair<int, int>, int> points;
    for (int i = 0; i < q; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        if (points.find(p) != points.end()) {
            add(0, 0, q, points[p], i, p);
            points.erase(p);
        }
        else {
            points[p] = i;
        }
    }

    for (auto it : points) {
        add(0, 0, q, it.second, q, it.first);
    }

    init();
    dfs(0, 0, q);
    for (int i = 0; i < q; i++) {
        cout << res[i] << ' ';
    }

}