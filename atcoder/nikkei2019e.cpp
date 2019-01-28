#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;
const int M = 100005;

vector<vector<int>> edges;
int a[N];
int parents[N];
int weight[N];

bool included[M];


int find(int a) {
    if (parents[a] == a) return a;
    int pa = find(parents[a]);
    parents[a] = pa;
    return pa;
}

void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parents[pb] = pa;
    weight[pa] += weight[pb];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] > a[1];
    });

    memset(included, false, sizeof(included));
    int ans = m;
    while (true) {
        bool finished = true;
        for (int i = 0; i < m; i++) {
            if (included[i]) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int ew = edges[i][2];
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) {
                if (weight[pu] >= ew) {
                    included[i] = true;
                    ans--;
                }
            }
            else {
                int w1 = weight[pu];
                int w2 = weight[pv];
                if (w1 + w2 >= ew) {
                    join(pu, pv);
                    included[i] = true;
                    ans--;
                    finished = false;
                }
            }
            
        }
        if (finished) break;
    }
    cout << ans;
}