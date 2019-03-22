#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Problem {
    int points;
    int decay;
    int t;

    bool operator<(const Problem& p) const {
        long long left = (long long)decay * p.t;
        long long right = (long long)p.decay * t;
        return left > right;
    }

};

class TheProgrammingContestDivOne {

public:
    int find(int T, vector<int> maxPoints, vector<int> pointsPerMinute, vector<int> requiredTime) {
        int n = maxPoints.size();
        vector<Problem> problems;
        for (int i = 0; i < n; i++) {
            problems.push_back({maxPoints[i], pointsPerMinute[i], requiredTime[i]});
        }

        sort(problems.begin(), problems.end());

        vector<long long> dp(T + 1, 0);

        for (int i = 0; i < n; i++) {
            int t = problems[i].t;
            for (int j = T; j >= t; j--) {
                long long points = problems[i].points - (long long)problems[i].decay * j;
                dp[j] = max(dp[j], dp[j - t] + points);
            }
        }
        long long ans = 0;
        for (int t = 0; t <= T; t++) {
            ans = max(ans, dp[t]);
        }
        return ans;
    }

};

int main() {
    TheProgrammingContestDivOne sol;
//     cout << sol.find(30,
// {100, 100, 100000},
// {1, 1, 100},
// {15, 15, 30}) << endl;

//     cout << sol.find(75,
// {250, 500, 1000},
// {2, 4, 8},
// {25, 25, 25}) << endl;

//     cout << sol.find(40000,
// {100000, 100000},
// {1, 100000},
// {50000, 30000}) << endl;

cout << sol.find(100000, {100000, 100000}, {90000, 1}, {1, 90000});
}