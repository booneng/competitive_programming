#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>


using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());

    vector<vector<int>> dp(n, vector<int>(k, 0));

    int left = 0;
    int ans = 0;
    vector<int> lefts(n);
    for (int right = 0; right < n; right++) {
        while (a[left] + 5 < a[right]) {
            left++;
        }
        lefts[right] = left;
    }

    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], i - lefts[i] + 1);
    }

    for (int i = 0; i < k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        int cleft = lefts[i];
        int size = i - cleft + 1;
        for (int j = 1; j < k; j++) {
            if (cleft == 0) dp[i][j] = size;
            else dp[i][j] = max(dp[i - 1][j], dp[cleft - 1][j - 1] + size);
        }
    }

    cout << dp[n - 1][k - 1];
}