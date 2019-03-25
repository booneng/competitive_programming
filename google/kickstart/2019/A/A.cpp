#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve() {
    int n, p;
    cin >> n >> p;

    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    long long sum = 0;
    for (int i = 0; i < p; i++) {
        sum += s[i];
    }

    long long ans = s[p - 1] * p - sum;
    for (int i = p; i < n; i++) {
        sum += s[i] - s[i - p];
        long long need = s[i] * p;
        long long training = need - sum;
        ans = min(ans, training);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}