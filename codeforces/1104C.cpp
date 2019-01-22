#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int col1 = 0;
    int col2 = 0;
    for (char c : s) {
        if (c == '0') {
            cout << 1 << ' ' << col1 + 1 << endl;
            col1 = (col1 + 1) % 4;
        }
        else {
            cout << 3 << ' ' << col2 + 1 << endl;
            col2 = (col2 + 2) % 4;
        }
    }
}