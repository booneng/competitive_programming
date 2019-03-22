#include <bits/stdc++.h>

using namespace std;


int find(int left, int right) {
    while (left + 1 < right) {
        int mid = (left + right) / 2;

        cout << "? " << left << ' ' << mid << endl;
        cout.flush();

        char ret;
        cin >> ret;
        if (ret == 'e') exit(0);
        if (ret == 'x') {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return left + 1;
}


void solve() {
    int x = 0;
    int y = 1;
    
    while (true) {

        cout << "? " << x << ' ' << y << endl;
        cout.flush();
        
        char ret;
        cin >> ret;
        if (ret == 'e') exit(0);

        if (ret == 'y') {
            x = y;
            y = y * 2;
        }
        else {
            int ans = find(x, y);
            cout << "! " << ans << endl;
            cout.flush();
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
