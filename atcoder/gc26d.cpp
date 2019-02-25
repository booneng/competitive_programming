#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int n;
const int mod = 1000000007;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

void Count(vector<int>& bottoms, vector<int>& h, int i) {
    if (i == n) {

    }

    bottoms[i] = 1;
    Count(bottoms, h, i + 1);
    bottoms[i] = 0;
    Count(bottoms, h, i + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> bottoms(n);
    Count(bottoms, h, 0);
    cout << ans;
}