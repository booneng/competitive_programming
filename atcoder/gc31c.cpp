#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int n;
int a, b;

void dfs(vector<int>& ans, int a, int b, int cn, int mask) {
    if (cn == 1) {
        ans.push_back(a);
        ans.push_back(b);
        return;
    }

    int c, d;

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) && ((a ^ b) & (1 << i))) {
            c = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) && i != c) {
            d = i;
            break;
        }
    }

    dfs(ans, a, a ^ (1 << d), cn - 1, mask + (1 << c));
    dfs(ans, a ^ (1 << c) ^ (1 << d), b, cn - 1, mask + (1 << c));
}

int main() {

    cin >> n >> a >> b;

    int tmp = a;
    int cnt_a, cnt_b;

    while (tmp) {
        if (tmp & 1) cnt_a++;
        tmp >>= 1;
    }

    tmp = b;
    while (tmp) {
        if (tmp & 1) cnt_b++;
        tmp >>= 1;
    }

    if ((cnt_a % 2) == (cnt_b % 2)) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    vector<int> ans;
    dfs(ans, a, b, n, 0);

    for (int i : ans) cout << i << ' ';
}