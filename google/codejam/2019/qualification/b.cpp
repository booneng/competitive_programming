#include <bits/stdc++.h>

using namespace std;

string solve() {
    int n;
    cin >> n;

    string lydia;
    cin >> lydia;

    bool go_bottom = true;
    if (lydia[lydia.size() - 1] == 'E') go_bottom = false;

    pair<int, int> pos1(1, 1);
    pair<int, int> pos2(1, 1);
    string ans;
    for (int i = 0; i < lydia.size(); i++) {
        if (pos1 == pos2) {
            if (lydia[i] == 'S') {
                pos1.second++;
                ans += 'E';
            }
            else {
                pos1.first++;
                ans += 'S';
            }
        }
        else {
            if (go_bottom) {
                if (pos1.first < n) {
                    pos1.first++;
                    ans += 'S';
                }
                else {
                    pos1.second++;
                    ans += 'E';
                }
            }
            else {
                if (pos1.second < n) {
                    pos1.second++;
                    ans += 'E';
                }
                else {
                    pos1.first++;
                    ans += 'S';
                }
            }
        }
        if (lydia[i] == 'S') pos2.first++;
        else pos2.second++;
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}