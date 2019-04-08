#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int n, k;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

pair<int, int> CalculateWays(int len) {
    if (len == 0) return {0, 1};
    if (len & 1) {
        int half = len >> 1;
        auto res = CalculateWays(half);
        int same = add(mul(res.first, res.first), mul(k - 1, mul(res.second, res.second)));
        int different = add(mul(2, mul(res.first, res.second)), mul(k - 2, mul(res.second, res.second)));
        return {same, different};
    }

    auto res = CalculateWays(len - 1);
    int same = mul(k - 1, res.second);
    int different = add(res.first, mul(k - 2, res.second));
    return {same, different};
}

int Calculate(const vector<int>& split, int left, int right) {
    if (right >= split.size()) {
        int len = right - left - 1;
        int first_choice = 1;
        if (left < 0) {
            len--;
            first_choice = k;
        }

        if (len == 0) return first_choice;

        auto res = CalculateWays(len - 1);
        return mul(first_choice, add(res.first, mul(k - 1, res.second)));
    }
    else if (left < 0) {
        if (right == 0) return 1;
        auto res = CalculateWays(right - left - 2);
        return add(res.first, mul(k - 1, res.second));
    }

    auto res = CalculateWays(right - left - 1);
    return split[left] == split[right] ? res.first : res.second;
}

int main() {
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    int ans = 1;
    for (int p = 0; p < 2; p++) {
        vector<int> split;
        for (int i = p; i < n; i += 2) {
            split.push_back(a[i]);
        }

        int l = -1;
        for (int i = 0; i < split.size(); i++) {
            if (split[i] == -1) continue;
            ans = mul(ans, Calculate(split, l, i));
            l = i;
        }
        ans = mul(ans, Calculate(split, l, split.size()));
    }


    cout << ans;

}