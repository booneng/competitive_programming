#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class TieForMax {

    
    double facs[52];

    double nCr(int n, int r) {
        return facs[n] / (facs[r] * facs[n - r]);
    }
    
public:

    double getProbability(int t, int p) {
        facs[0] = 1;
        for (int i = 1; i < 52; i++) {
            facs[i] = (double)i * facs[i - 1];
        }

        // dp[i][j][k] = number of ways to distribute i tokens into j piles s.t. each pile has at most k tokens
        vector<vector<vector<double>>> dp(t + 1, vector<vector<double>>(p + 1, vector<double>(t + 1, 0.0)));

        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= t; j++) {
                dp[0][i][j] = 1;
            }
        }

        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= p; j++) {
                for (int k = 0; k <= t; k++) {
                    for (int l = 0; l <= min(i, k); l++) {
                        dp[i][j][k] += nCr(i, l) * dp[i - l][j - 1][k];
                    }
                }
            }
        }

        double total_ways = 0;
        for (int x = 1; x <= t; x++) {
            total_ways += p * nCr(t, x) * dp[t - x][p - 1][x - 1];
        }

        double div = 1;
        for (int i = 0; i < t; i++) div *= p;
        double ans = 1 - (total_ways / div);
        return ans;
    }
};

int main() {
    TieForMax sol;
    cout << sol.getProbability(7, 1) << endl;
    cout << sol.getProbability(2, 2) << endl;
}