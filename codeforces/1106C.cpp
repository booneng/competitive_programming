#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n / 2; i++) {
        int s = a[i] + a[n - 1 - i];
        ans += s * s;
    }
    cout << ans;
}