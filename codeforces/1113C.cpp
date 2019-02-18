#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, long long> seen_odd;
    map<int, long long> seen_even;
    seen_odd[0]++;
    int x = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x ^= a;
        if (i % 2) {
            cnt += seen_odd[x];
            seen_odd[x]++;
        }
        else {
            cnt += seen_even[x];
            seen_even[x]++;
        }
    }
    cout << cnt;
}