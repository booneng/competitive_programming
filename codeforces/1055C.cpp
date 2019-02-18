#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int l1, r1, t1;
    int l2, r2, t2;

    cin >> l1 >> r1 >> t1;
    cin >> l2 >> r2 >> t2;

    int g = gcd(t1, t2);

    int la = l1 % g;
    int lb = l2 % g;

    int ra = la + (r1 - l1);
    int rb = lb + (r2 - l2);

    int ans = 0;
    {
        int r = min(ra, rb);
        int l = max(la, lb);
        ans = max(ans, r - l + 1);
    }
    {
        int r = min(ra + g, rb);
        int l = max(la + g, lb);
        ans = max(ans, r - l + 1);
    }
    {
        int r = min(ra, rb + g);
        int l = max(la, lb + g);
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}
