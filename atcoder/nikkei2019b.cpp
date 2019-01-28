#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string a, b, c;
    cin >> n;
    cin >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) continue;
        if (a[i] == b[i] || a[i] == c[i] || b[i] == c[i]) ans++;
        else ans += 2;
    }
    cout << ans;
}
