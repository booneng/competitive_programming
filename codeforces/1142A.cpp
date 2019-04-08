#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long n, k;
long long a, b;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> n >> k;
    cin >> a >> b;

    long long left = numeric_limits<long long>::max();
    long long right = 0;

    for (int x = 0; x < n; x++) {
        long long c = a + b;
        long long val = n * k / gcd(n * k, abs(k * x + c));
        left = min(left, val);
        right = max(right, val);

        c = a - b;
        val = n * k / gcd(n * k, abs(k * x + c));
        left = min(left, val);
        right = max(right, val);
        
    }

    cout << left << ' ' << right << endl;
}
