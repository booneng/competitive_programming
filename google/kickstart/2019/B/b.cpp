#include <bits/stdc++.h>

using namespace std;

const int T = 10105;
const int HI = 10001;
int dp[T];

struct Stone {
    int s, e, l;
    
    bool operator<(const Stone& st) const {
        return s * st.l < st.s * l;
    }
};

int solve() {
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    vector<Stone> stones(n);

    for (int i = 0; i < n; i++) {
        cin >> stones[i].s >> stones[i].e >> stones[i].l;
    }

    sort(stones.begin(), stones.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < HI; t++) {
            int score = stones[i].e - stones[i].l * t;
            dp[t] = max(dp[t], score + dp[t + stones[i].s]);
        }
    }
    

    
    return dp[0];
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}
