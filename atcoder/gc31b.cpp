#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int colors[200005];
int c[200005];

const int mod = 1000000007;

void add(int& a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {

    memset(colors, 0, sizeof(colors));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> c[i];

    int dp = 1;
    for (int i = 0; i < n; i++) {
        int x = c[i];
        if (i > 0 && c[i] == c[i - 1]) continue;

        add(colors[x], dp);
        dp = colors[x];
    }

    cout << dp;


}