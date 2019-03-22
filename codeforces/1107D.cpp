#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<bool> Parse(string s) {
    vector<bool> res;
    
    for (int i = 0; i < s.size(); i++) {
        int num;
        if (isdigit(s[i])) {
            num = s[i] - '0';
        }
        else {
            num = s[i] - 'A' + 10;
        }

        for (int i = 3; i >= 0; i--) {
            if (num & (1 << i)) {
                res.push_back(1);
            }
            else {
                res.push_back(0);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<vector<bool>> grid(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid[i] = Parse(s);
    }

    int g = n;
    for (int i = 0; i < n; i++) {
        int j = 1;
        int len = 1;
        while (j < n) {
            if (grid[i][j] != grid[i][j - 1]) {
                g = gcd(g, len);
                len = 0;
            }
            len++;
            j++;
        }
        g = gcd(g, len);
    }

    for (int i = 0; i < n; i++) {
        int j = 1;
        int len = 1;
        while (j < n) {
            if (grid[j][i] != grid[j - 1][i]) {
                g = gcd(g, len);
                len = 0;
            }
            len++;
            j++;
        }
        g = gcd(g, len);
    }

    cout << g;
}