#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += c[i];
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            q.push(i);
        }
    }

    vector<int> vals(n);

    int idx = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        vals[cur] = c[idx++];
        for (int next : adj[cur]) {
            adj[next].erase(cur);
            if (adj[next].size() == 1) {
                q.push(next);
            }
        }
    }

    cout << sum << endl;
    for (int i : vals) {
        cout << i << ' ';
    }
}