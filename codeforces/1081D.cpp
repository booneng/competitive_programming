#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;

    bool operator<(const Edge& e) const {
        return w < e.w;
    }

};

bool specials[100005];
int parents[100005];
vector<Edge> edges;
int n, m, k;

int find(int u) {
    int p = parents[u];
    if (p == u) return p;
    parents[u] = find(p);
    return parents[u];
}

void join(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (specials[pu]) {
            parents[pv] = pu;
        }
        else {
            parents[pu] = pv;
        }

        if (specials[pu] && specials[pv]) {
            k--;
        }
    }
}

int main() {
    int t;
    cin >> n >> m >> k;
    t = k;
    memset(specials, false, (n + 1) * sizeof(bool));
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        specials[a] = true;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    for (auto& e : edges) {
        int pu = find(e.u);
        int pv = find(e.v);

        join(pu, pv);
        if (k == 1) {
            for (int i = 0; i < t; i++) {
                cout << e.w << ' ';
            }
            break;
        }
    }

}