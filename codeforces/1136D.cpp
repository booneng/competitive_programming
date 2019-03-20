#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 300005;

int n, m;
int p[MAXN];
set<int> adj[MAXN];
int natsya;
int ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    natsya = p[n - 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }

    set<int> front;
    front.insert(natsya);
    for (int i = n - 2; i >= 0; i--) {
        int cur = p[i];
        int cnt = 0;
        for (int j : adj[cur]) {
            if (front.find(j) != front.end()) {
                cnt++;
            }
        }

        if (cnt < front.size()) {
            front.insert(cur);
        }
    }
    cout << n - front.size();
}