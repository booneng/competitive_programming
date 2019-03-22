#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, b;
    cin >> n >> b;
    long long ans = 1LL << 60;
    for (long long i = 2; i <= b; i++) {
        if (i * i > b) i = b;
        long long cnt = 0;
        while (b % i == 0) {
            cnt++;
            b /= i;
        }

        if (cnt == 0) continue;

        long long mul = 1;
        long long cnt2 = 0;
        while (mul <= n / i) {
            mul *= i;
            cnt2 += n / mul;
        }

        ans = min(ans, cnt2 / cnt);
    }
    cout << ans;
}