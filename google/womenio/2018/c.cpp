#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l;
    cin >> l;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int p1 = 0, p2 = 0, p3 = 0;

    for (int i = 0; i < l; i++) {
        if (s1[i] != s2[i]) {
            p1 = i;
            break;
        }
    }

    for (int i = 0; i < l; i++) {
        if (s1[i] != s3[i]) {
            p2 = i;
            break;
        }
    }

    for (int i = 0; i < l; i++) {
        if (s2[i] != s3[i]) {
            p3 = i;
            break;
        }
    }

    bool c1, c2, c3;
    if (p1 == p2 && p2 == p3) {
        c1 = true;
        c2 = true;
        c3 = true;
    }
    else if (p2 > p1) {
        c1 = true;
        c2 = false;
        c3 = true;
        if (s3[p2] == s2[p1] && s1[p2] == s1[p1]) {
            c1 = false;
        }
        if (s1[p2] == s2[p1] && s3[p2] == s3[p1]) {
            c3 = false;
        }
    }
    else if (p1 > p2) {
        c1 = true;
        c2 = true;
        c3 = false;
        if (s1[p1] == s3[p2] && s2[p1] == s2[p2]) {
            c2 = false;
        }
        if (s2[p1] == s3[p2] && s1[p1] == s1[p2]) {
            c1 = false;
        }
    }
    else {
        c1 = false;
        c2 = true;
        c3 = true;
        if (s2[p3] == s1[p1] && s3[p3] == s3[p1]) {
            c3 = false;
        }
        if (s3[p3] == s1[p1] && s2[p3] == s2[p1]) {
            c2 = false;
        }
    }

    cout << (c1 ? "YES " : "NO ");
    cout << (c2 ? "YES " : "NO ");
    cout << (c3 ? "YES " : "NO ");
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}