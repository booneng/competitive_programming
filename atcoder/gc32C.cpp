#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100005];

int a = 0, b = 0;
int paths = 0;

bool dfs(int i, int p) {
    if (i == a) return true;
    if (i == b) return false;
    for (int j : adj[i]) {
        if (j == p) continue;
        return dfs(j, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2) {
            cout << "No";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 4) {
            cout << "Yes";
            return 0;
        }
        else if (adj[i].size() == 4) {
            cnt++;
            if (!a) {
                a = i;
            }
            else {
                b = i;
            }
        }
    }

    if (cnt > 2) {
        cout << "Yes";
        return 0;
    }
    else if (cnt < 2) {
        cout << "No";
        return 0;
    }

    for (int i : adj[a]) {
        if (dfs(i, a)) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}