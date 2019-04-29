#include <bits/stdc++.h>

using namespace std;

string grid[30];
int r, c;


void solve(ifstream& cin, ofstream& cout) {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '?') {
                for (int k = j - 1; k >= 0; k--) {
                    if (grid[i][k] == '?') grid[i][k] = grid[i][j];
                    else break;
                }

                while (j < c - 1 && grid[i][j + 1] == '?') {
                    j++;
                    grid[i][j] = grid[i][j - 1];
                }
            }
        }
    }

    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '?') grid[i][j] = grid[i - 1][j];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '?') grid[i][j] = grid[i + 1][j];
        }
    }

    for (int i = 0; i < r; i++) {
        cout << grid[i] << endl;
    }
}

int main() {
    ifstream cin("A-large-practice.in");
    ofstream cout("test.out");
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":" << endl;
        solve(cin, cout);
    }
}