#include <bits/stdc++.h>

using namespace std;


int find(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;

        cout << "? " << left << ' ' << mid;
        fflush(stdout);

        string s;
        cin >> s;
        if (s == "e") exit(0);
        int ret = stoi(s);

        // int ret;
        // cin >> ret;

        if (ret == left) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left + 1;
}


void solve() {
    int x = 0;
    int y = 1;
    
    while (true) {

        cout << "? " << x << ' ' << y;
        fflush(stdout);

        // string s;
        // cin >> s;
        // if (s == "e") exit(0);
        // int ret = stoi(s);

        int ret;
        cin >> ret;

        if (ret == y) {
            x = y;
            y = y * 2;
        }
        else {
          cout << "! " << x;
          fflush(stdout);
          return;
            int ans = find(x, y);
            cout << "! " << ans;
            fflush(stdout);
            return;
        }
    }

}


int main() {
    string s;
    cin >> s;
    while (s == "start") {
        solve();
        cin >> s;
    }
}
