#include <bits/stdc++.h>

using namespace std;

int n, b, f;

const int MAGIC = 32;

void solve() {
    cin >> n >> b >> f;
    vector<string> res;
    for (int t = 0; t < 5; t++) {
        string s;
        for (int i = 0; i < n; i++) {
            int r = i & 31;
            if ((r >> t) & 1) {
                s += '1';
            }
            else {
                s += '0';
            }
        }
        cout << s << endl;
        cout.flush();
        cin >> s;
        res.push_back(s);
    }


    int idx = 0;
    string ans;
    for (int i = 0; i < n; i++) {
        int r = i & 31;
        int num = 0;
        for (int j = 0; j < 5; j++) {
            if (res[j][idx] == '1') {
                num += 1 << j;
            }
        }

        if (num == r) {
            idx++;
        }
        else {
            ans += to_string(i) + ' ';
        }
        
    }

    cout << ans << endl;
    cout.flush();

    int r;
    cin >> r;
    if (r == -1) exit(0);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}